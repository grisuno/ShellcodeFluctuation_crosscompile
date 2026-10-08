# root

*Community 0 | 2 files | cohesion 1.00*

## Definition

This community groups 2 file(s) rooted at `root` with dominant language h (cohesion 1.00). Central symbols: `FluctuationMetadata`, `HEADER_H`, `HookTrampolineBuffers`, `HookedSleep`, `MySleep`, `UPTR`, `VEHHandler`, `collectMemPriv`. Core file: `header.h` (18 symbols).

## Files

| File | Language | Layer | Symbols | Doc |
|------|----------|-------|---------|-----|
| `header.h` | h | utility | 18 | no |
| `main.c` | c | utility | 13 | no |

## Key Symbols

- `HEADER_H` (macro, `header.h:2`) `#define HEADER_H`
- `UPTR` (type_alias, `header.h:11`) `typedef UINT64 UPTR;` - ifdef _WIN64
- `UPTR` (type_alias, `header.h:13`) `typedef UINT32 UPTR;` - else
- `HookedSleep` (struct, `header.h:27`)
- `FluctuationMetadata` (struct, `header.h:32`)
- `HookTrampolineBuffers` (struct, `header.h:40`)
- `log` (macro, `header.h:48`) `#define log(...)`
- `g_hookedSleep` (variable, `header.h:51`) `extern HookedSleep g_hookedSleep;` - DWORD  protect; } FluctuationMetadata; typedef struct { BYTE *originalBytes; DWORD originalBytesSize
- `g_fluctuationData` (variable, `header.h:52`) `extern FluctuationMetadata g_fluctuationData;`
- `g_fluctuate` (variable, `header.h:53`) `extern TypeOfFluctuation g_fluctuate;`
- `hookSleep` (function, `header.h:56`) `bool hookSleep(void);` - DWORD originalBytesSize; BYTE *previousBytes; DWORD previousBytesSize; } HookTrampolineBuffers; /* -
- `injectShellcode` (function, `header.h:57`) `bool injectShellcode(uint8_t *sc, SIZE_T scSize, HANDLE *outThread);`
- `readShellcode` (function, `header.h:58`) `bool readShellcode(const char *path, uint8_t **out, SIZE_T *outSize);`
- `initializeShellcodeFluctuation` (function, `header.h:59`) `void initializeShellcodeFluctuation(LPVOID caller);`
- `shellcodeEncryptDecrypt` (function, `header.h:60`) `void shellcodeEncryptDecrypt(LPVOID caller);`
- `fastTrampoline` (function, `header.h:61`) `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffe`
- `xor32` (function, `header.h:62`) `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key);`
- `isShellcodeThread` (function, `header.h:63`) `bool isShellcodeThread(LPVOID addr);`
- `get_return_address` (function, `main.c:3`) `static inline UPTR get_return_address(void)`
- `MySleep` (function, `main.c:18`) `static void WINAPI MySleep(DWORD ms)` - { #ifdef _WIN64 return (UPTR)__builtin_return_address(0); #else /* 32 bits – también funciona return
- `fastTrampoline` (function, `main.c:43`) `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffe` - b.originalBytesSize = sizeof(g_hookedSleep.sleepStub); /* des-hook temporal fastTrampoline(false, (B
- `xor32` (function, `main.c:93`) `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)` - memcpy(target, b->originalBytes, b->originalBytesSize); size = b->originalBytesSize; } typeNtFlushIn
- `collectMemPriv` (function, `main.c:105`) `static void collectMemPriv(void)`
- `initializeShellcodeFluctuation` (function, `main.c:131`) `void initializeShellcodeFluctuation(LPVOID caller)` - (mbi.Protect & (PAGE_EXECUTE_READWRITE\|PAGE_EXECUTE_READ\|PAGE_READWRITE)) ) { if (used == alloc) { a
- `isShellcodeThread` (function, `main.c:159`) `bool isShellcodeThread(LPVOID addr)` - g_fluctuationData.shellcodeSize = m->RegionSize; g_fluctuationData.currentlyEncrypted = false; g_flu
- `shellcodeEncryptDecrypt` (function, `main.c:169`) `void shellcodeEncryptDecrypt(LPVOID caller)` - ExitProcess(0); } /* ------------- es thread shellcode? -- bool isShellcodeThread(LPVOID addr) { MEM
- `VEHHandler` (function, `main.c:207`) `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)` - VirtualProtect(g_fluctuationData.shellcodeAddr, g_fluctuationData.shellcodeSize, PAGE_NOACCESS, &old
- `readShellcode` (function, `main.c:230`) `bool readShellcode(const char *path, uint8_t **out, SIZE_T *outSize)` - #endif log("[.] AV at 0x%p", (void*)ip); UPTR base = (UPTR)g_fluctuationData.shellcodeAddr; UPTR end
- `runShellcode` (function, `main.c:244`) `static DWORD WINAPI runShellcode(LPVOID param)` - bool readShellcode(const char *path, uint8_t **out, SIZE_T *outSize) { HANDLE h = CreateFileA(path,G
- `injectShellcode` (function, `main.c:250`) `bool injectShellcode(uint8_t *sc, SIZE_T scSize, HANDLE *outThread)`

## Internal vs External Edges

- Internal resolved imports (EXTRACTED): 1
- Cross-boundary resolved imports (EXTRACTED): 0

## Connections

- [INFERRED] shares_context community 0 <-> 1 (strength 0.5): Inferred shared context (layer utility) with no import path between community 0 (root) and community 1 (orphans).

## Risks

- [dataflow UNCHECKED_ALLOC] `main.c:236` `readShellcode` `buf`: Result of allocator stored in `buf` is never checked against NULL.

## Open Questions

- Why do 2 file(s) lack file-level docs (e.g. `header.h`)? What purpose do they serve?
- What would break if the most connected file in root changed?
- Should root be split, given cohesion 1.00?

## Sources

- `header.h`
- `main.c`
