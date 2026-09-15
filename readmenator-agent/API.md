# API

## header.h

### void (function) `typedef void (WINAPI *typeSleep)(DWORD ms);`
- Defined: `header.h:24`
- Doc: #ifdef _WIN64 typedef UINT64  UPTR; #else typedef UINT32  UPTR; #endif /* ---------- tipos de la fluctuación ---------- 
- Imported by: `main.c`

### DWORD (function) `typedef DWORD (NTAPI *typeNtFlushInstructionCache)(HANDLE,PVOID,ULONG);`
- Defined: `header.h:25`
- Imported by: `main.c`

### hookSleep (function) `bool hookSleep(void);`
- Defined: `header.h:56`
- Doc: DWORD originalBytesSize; BYTE *previousBytes; DWORD previousBytesSize; } HookTrampolineBuffers; /* ---------- macros / u
- Imported by: `main.c`

### injectShellcode (function) `bool injectShellcode(uint8_t *sc, SIZE_T scSize, HANDLE *outThread);`
- Defined: `header.h:57`
- Imported by: `main.c`

### readShellcode (function) `bool readShellcode(const char *path, uint8_t **out, SIZE_T *outSize);`
- Defined: `header.h:58`
- Imported by: `main.c`

### initializeShellcodeFluctuation (function) `void initializeShellcodeFluctuation(LPVOID caller);`
- Defined: `header.h:59`
- Imported by: `main.c`

### shellcodeEncryptDecrypt (function) `void shellcodeEncryptDecrypt(LPVOID caller);`
- Defined: `header.h:60`
- Imported by: `main.c`

### fastTrampoline (function) `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b);`
- Defined: `header.h:61`
- Imported by: `main.c`

### xor32 (function) `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key);`
- Defined: `header.h:62`
- Imported by: `main.c`

### isShellcodeThread (function) `bool isShellcodeThread(LPVOID addr);`
- Defined: `header.h:63`
- Imported by: `main.c`

### VEHHandler (function) `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp);`
- Defined: `header.h:64`
- Imported by: `main.c`

## main.c

### get_return_address (function) `static inline UPTR get_return_address(void)`
- Defined: `main.c:2`
- Doc: include "header.h"
- Depends on: `header.h`

### MySleep (function) `static void WINAPI MySleep(DWORD ms)`
- Defined: `main.c:18`
- Doc: { #ifdef _WIN64 return (UPTR)__builtin_return_address(0); #else /* 32 bits – también funciona return (UPTR)__builtin_ret
- Depends on: `header.h`

### fastTrampoline (function) `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)`
- Defined: `main.c:43`
- Doc: b.originalBytesSize = sizeof(g_hookedSleep.sleepStub); /* des-hook temporal fastTrampoline(false, (BYTE*)Sleep, (LPVOID)
- Depends on: `header.h`

### xor32 (function) `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)`
- Defined: `main.c:93`
- Doc: memcpy(target, b->originalBytes, b->originalBytesSize); size = b->originalBytesSize; } typeNtFlushInstructionCache fn; f
- Depends on: `header.h`

### collectMemPriv (function) `static void collectMemPriv(void)`
- Defined: `main.c:104`
- Depends on: `header.h`

### initializeShellcodeFluctuation (function) `void initializeShellcodeFluctuation(LPVOID caller)`
- Defined: `main.c:131`
- Doc: (mbi.Protect & (PAGE_EXECUTE_READWRITE|PAGE_EXECUTE_READ|PAGE_READWRITE)) ) { if (used == alloc) { alloc = alloc ? alloc
- Depends on: `header.h`

### isShellcodeThread (function) `bool isShellcodeThread(LPVOID addr)`
- Defined: `main.c:159`
- Doc: g_fluctuationData.shellcodeSize = m->RegionSize; g_fluctuationData.currentlyEncrypted = false; g_fluctuationData.encodeK
- Depends on: `header.h`

### shellcodeEncryptDecrypt (function) `void shellcodeEncryptDecrypt(LPVOID caller)`
- Defined: `main.c:169`
- Doc: ExitProcess(0); } /* ------------- es thread shellcode? -- bool isShellcodeThread(LPVOID addr) { MEMORY_BASIC_INFORMATIO
- Depends on: `header.h`

### VEHHandler (function) `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)`
- Defined: `main.c:207`
- Doc: VirtualProtect(g_fluctuationData.shellcodeAddr, g_fluctuationData.shellcodeSize, PAGE_NOACCESS, &old); log("[>] Flipped 
- Depends on: `header.h`

### readShellcode (function) `bool readShellcode(const char *path, uint8_t **out, SIZE_T *outSize)`
- Defined: `main.c:230`
- Doc: #endif log("[.] AV at 0x%p", (void*)ip); UPTR base = (UPTR)g_fluctuationData.shellcodeAddr; UPTR end  = base + g_fluctua
- Depends on: `header.h`

### runShellcode (function) `static DWORD WINAPI runShellcode(LPVOID param)`
- Defined: `main.c:244`
- Doc: bool readShellcode(const char *path, uint8_t **out, SIZE_T *outSize) { HANDLE h = CreateFileA(path,GENERIC_READ,FILE_SHA
- Depends on: `header.h`

### injectShellcode (function) `bool injectShellcode(uint8_t *sc, SIZE_T scSize, HANDLE *outThread)`
- Defined: `main.c:249`
- Depends on: `header.h`

### main (function) `int main(int argc, char **argv)`
- Defined: `main.c:264`
- Doc: bool injectShellcode(uint8_t *sc, SIZE_T scSize, HANDLE *outThread) { void *mem = VirtualAlloc(NULL,scSize,MEM_COMMIT,PA
- Depends on: `header.h`

### log (function) `log("[>] MySleep(%lu)", ms);`
- Defined: `main.c:24`
- Depends on: `header.h`

### Sleep (function) `Sleep(ms);`
- Defined: `main.c:33`
- Depends on: `header.h`

### memcpy (function) `memcpy(code+2, &jump, 8);`
- Defined: `main.c:59`
- Depends on: `header.h`

### VirtualProtect (function) `VirtualProtect(target, size, old, &old);`
- Defined: `main.c:87`
- Depends on: `header.h`

### ExitProcess (function) `ExitProcess(0);`
- Defined: `main.c:155`
- Depends on: `header.h`

### CloseHandle (function) `CloseHandle(h);`
- Defined: `main.c:238`
- Depends on: `header.h`

### VirtualFree (function) `VirtualFree(mem,0,MEM_RELEASE);`
- Defined: `main.c:257`
- Depends on: `header.h`

### AddVectoredExceptionHandler (function) `AddVectoredExceptionHandler(1,VEHHandler);`
- Defined: `main.c:298`
- Depends on: `header.h`

### WaitForSingleObject (function) `WaitForSingleObject(thr,INFINITE);`
- Defined: `main.c:306`
- Depends on: `header.h`
