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
  - `HEADER_H` (macro, line 2)
  - `log` (macro, line 48)

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
