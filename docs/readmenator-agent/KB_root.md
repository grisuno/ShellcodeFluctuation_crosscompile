# Subsystem: root

## app.py
- Layer: utility
- Doc: _*_ coding: utf8 _*_
- Language: py

## header.h
- Layer: utility
- Doc: ifndef HEADER_H define HEADER_H  include <windows.h> include <stdio.h> include <stdlib.h> include <stdint.h> include <st
- Language: h
- Symbols:
  - `HookedSleep` (struct, line 27)
  - `FluctuationMetadata` (struct, line 32)
  - `HookTrampolineBuffers` (struct, line 40)
  - `UPTR` (type_alias, line 11) `typedef UINT64 UPTR;`
  - `UPTR` (type_alias, line 13) `typedef UINT32 UPTR;`
  - `void` (function, line 24) `typedef void (WINAPI *typeSleep)(DWORD ms);`
  - `DWORD` (function, line 25) `typedef DWORD (NTAPI *typeNtFlushInstructionCache)(HANDLE,PVOID,ULONG);`
  - `hookSleep` (function, line 56) `bool hookSleep(void);`
  - `injectShellcode` (function, line 57) `bool injectShellcode(uint8_t *sc, SIZE_T scSize, HANDLE *outThread);`
  - `readShellcode` (function, line 58) `bool readShellcode(const char *path, uint8_t **out, SIZE_T *outSize);`
  - `initializeShellcodeFluctuation` (function, line 59) `void initializeShellcodeFluctuation(LPVOID caller);`
  - `shellcodeEncryptDecrypt` (function, line 60) `void shellcodeEncryptDecrypt(LPVOID caller);`
  - `fastTrampoline` (function, line 61) `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b);`
  - `xor32` (function, line 62) `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key);`
  - `isShellcodeThread` (function, line 63) `bool isShellcodeThread(LPVOID addr);`
  - `VEHHandler` (function, line 64) `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp);`
  - `g_hookedSleep` (variable, line 51) `extern HookedSleep g_hookedSleep;`
  - `g_fluctuationData` (variable, line 52) `extern FluctuationMetadata g_fluctuationData;`
  - `g_fluctuate` (variable, line 53) `extern TypeOfFluctuation g_fluctuate;`
  - `HEADER_H` (macro, line 2) `#define HEADER_H`
  - `log` (macro, line 48) `#define log(...)`
- Imported by: `main.c`

## install.sh
- Layer: utility
- Language: sh

## main.c
- Layer: utility
- Doc: include "header.h"
- Language: c
- Symbols:
  - `get_return_address` (function, line 2) `static inline UPTR get_return_address(void)`
  - `MySleep` (function, line 18) `static void WINAPI MySleep(DWORD ms)`
  - `fastTrampoline` (function, line 43) `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)`
  - `xor32` (function, line 93) `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)`
  - `collectMemPriv` (function, line 104) `static void collectMemPriv(void)`
  - `initializeShellcodeFluctuation` (function, line 131) `void initializeShellcodeFluctuation(LPVOID caller)`
  - `isShellcodeThread` (function, line 159) `bool isShellcodeThread(LPVOID addr)`
  - `shellcodeEncryptDecrypt` (function, line 169) `void shellcodeEncryptDecrypt(LPVOID caller)`
  - `VEHHandler` (function, line 207) `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)`
  - `readShellcode` (function, line 230) `bool readShellcode(const char *path, uint8_t **out, SIZE_T *outSize)`
  - `runShellcode` (function, line 244) `static DWORD WINAPI runShellcode(LPVOID param)`
  - `injectShellcode` (function, line 249) `bool injectShellcode(uint8_t *sc, SIZE_T scSize, HANDLE *outThread)`
  - `main` (function, line 264) `int main(int argc, char **argv)`
  - `log` (function, line 24) `log("[>] MySleep(%lu)", ms);`
  - `Sleep` (function, line 33) `Sleep(ms);`
  - `memcpy` (function, line 59) `memcpy(code+2, &jump, 8);`
  - `VirtualProtect` (function, line 87) `VirtualProtect(target, size, old, &old);`
  - `ExitProcess` (function, line 155) `ExitProcess(0);`
  - `CloseHandle` (function, line 238) `CloseHandle(h);`
  - `VirtualFree` (function, line 257) `VirtualFree(mem,0,MEM_RELEASE);`
  - `AddVectoredExceptionHandler` (function, line 298) `AddVectoredExceptionHandler(1,VEHHandler);`
  - `WaitForSingleObject` (function, line 306) `WaitForSingleObject(thr,INFINITE);`
- Depends on: `header.h`
