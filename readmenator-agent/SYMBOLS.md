# Symbols

| Symbol | Kind | File:Line | Signature |
|--------|------|-----------|-----------|
| `DWORD` | function | `header.h:25` | `typedef DWORD (NTAPI *typeNtFlushInstructionCache)(HANDLE,PVOID,ULONG);` |
| `FluctuationMetadata` | struct | `header.h:32` | `` |
| `HEADER_H` | macro | `header.h:2` | `#define HEADER_H` |
| `HookTrampolineBuffers` | struct | `header.h:40` | `` |
| `HookedSleep` | struct | `header.h:27` | `` |
| `UPTR` | type_alias | `header.h:11` | `typedef UINT64 UPTR;` |
| `UPTR` | type_alias | `header.h:13` | `typedef UINT32 UPTR;` |
| `VEHHandler` | function | `header.h:64` | `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp);` |
| `fastTrampoline` | function | `header.h:61` | `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b);` |
| `g_fluctuate` | variable | `header.h:53` | `extern TypeOfFluctuation g_fluctuate;` |
| `g_fluctuationData` | variable | `header.h:52` | `extern FluctuationMetadata g_fluctuationData;` |
| `g_hookedSleep` | variable | `header.h:51` | `extern HookedSleep g_hookedSleep;` |
| `hookSleep` | function | `header.h:56` | `bool hookSleep(void);` |
| `initializeShellcodeFluctuation` | function | `header.h:59` | `void initializeShellcodeFluctuation(LPVOID caller);` |
| `injectShellcode` | function | `header.h:57` | `bool injectShellcode(uint8_t *sc, SIZE_T scSize, HANDLE *outThread);` |
| `isShellcodeThread` | function | `header.h:63` | `bool isShellcodeThread(LPVOID addr);` |
| `log` | macro | `header.h:48` | `#define log(...)` |
| `readShellcode` | function | `header.h:58` | `bool readShellcode(const char *path, uint8_t **out, SIZE_T *outSize);` |
| `shellcodeEncryptDecrypt` | function | `header.h:60` | `void shellcodeEncryptDecrypt(LPVOID caller);` |
| `void` | function | `header.h:24` | `typedef void (WINAPI *typeSleep)(DWORD ms);` |
| `xor32` | function | `header.h:62` | `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key);` |
| `AddVectoredExceptionHandler` | function | `main.c:298` | `AddVectoredExceptionHandler(1,VEHHandler);` |
| `CloseHandle` | function | `main.c:238` | `CloseHandle(h);` |
| `ExitProcess` | function | `main.c:155` | `ExitProcess(0);` |
| `MySleep` | function | `main.c:18` | `static void WINAPI MySleep(DWORD ms)` |
| `Sleep` | function | `main.c:33` | `Sleep(ms);` |
| `VEHHandler` | function | `main.c:207` | `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)` |
| `VirtualFree` | function | `main.c:257` | `VirtualFree(mem,0,MEM_RELEASE);` |
| `VirtualProtect` | function | `main.c:87` | `VirtualProtect(target, size, old, &old);` |
| `WaitForSingleObject` | function | `main.c:306` | `WaitForSingleObject(thr,INFINITE);` |
| `collectMemPriv` | function | `main.c:104` | `static void collectMemPriv(void)` |
| `fastTrampoline` | function | `main.c:43` | `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)` |
| `get_return_address` | function | `main.c:2` | `static inline UPTR get_return_address(void)` |
| `initializeShellcodeFluctuation` | function | `main.c:131` | `void initializeShellcodeFluctuation(LPVOID caller)` |
| `injectShellcode` | function | `main.c:249` | `bool injectShellcode(uint8_t *sc, SIZE_T scSize, HANDLE *outThread)` |
| `isShellcodeThread` | function | `main.c:159` | `bool isShellcodeThread(LPVOID addr)` |
| `log` | function | `main.c:24` | `log("[>] MySleep(%lu)", ms);` |
| `main` | function | `main.c:264` | `int main(int argc, char **argv)` |
| `memcpy` | function | `main.c:59` | `memcpy(code+2, &jump, 8);` |
| `readShellcode` | function | `main.c:230` | `bool readShellcode(const char *path, uint8_t **out, SIZE_T *outSize)` |
| `runShellcode` | function | `main.c:244` | `static DWORD WINAPI runShellcode(LPVOID param)` |
| `shellcodeEncryptDecrypt` | function | `main.c:169` | `void shellcodeEncryptDecrypt(LPVOID caller)` |
| `xor32` | function | `main.c:93` | `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)` |
