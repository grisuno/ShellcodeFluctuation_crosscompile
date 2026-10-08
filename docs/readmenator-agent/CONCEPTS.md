# Concepts

Nouns map atomically to file sets (EXTRACTED); verbs aggregate structural edges (INFERRED).

- `shellcode` | files=2 | mentions=28 | `header.h`, `main.c`
- `fluctuation` | files=2 | mentions=27 | `header.h`, `main.c`
- `size` | files=2 | mentions=27 | `header.h`, `main.c`
- `data` | files=2 | mentions=18 | `header.h`, `main.c`
- `sleep` | files=2 | mentions=15 | `header.h`, `main.c`
- `bytes` | files=2 | mentions=11 | `header.h`, `main.c`
- `read` | files=2 | mentions=10 | `header.h`, `main.c`
- `log` | files=2 | mentions=9 | `header.h`, `main.c`
- `protect` | files=2 | mentions=9 | `header.h`, `main.c`
- `thread` | files=2 | mentions=9 | `header.h`, `main.c`
- `dword` | files=2 | mentions=8 | `header.h`, `main.c`
- `fluctuate` | files=2 | mentions=7 | `header.h`, `main.c`
- `hook` | files=2 | mentions=7 | `header.h`, `main.c`
- `hooked` | files=2 | mentions=7 | `header.h`, `main.c`
- `original` | files=2 | mentions=7 | `header.h`, `main.c`
- `trampoline` | files=2 | mentions=7 | `header.h`, `main.c`
- `uptr` | files=2 | mentions=7 | `header.h`, `main.c`
- `byte` | files=2 | mentions=5 | `header.h`, `main.c`
- `decrypt` | files=2 | mentions=5 | `header.h`, `main.c`
- `type` | files=2 | mentions=5 | `header.h`, `main.c`
- `else` | files=2 | mentions=4 | `header.h`, `main.c`
- `encrypt` | files=2 | mentions=4 | `header.h`, `main.c`
- `fast` | files=2 | mentions=4 | `header.h`, `main.c`
- `metadata` | files=2 | mentions=4 | `header.h`, `main.c`
- `globales` | files=2 | mentions=3 | `header.h`, `main.c`
- `inject` | files=2 | mentions=3 | `header.h`, `main.c`
- `ifdef` | files=2 | mentions=2 | `header.h`, `main.c`
- `initialize` | files=2 | mentions=2 | `header.h`, `main.c`
- `win64` | files=2 | mentions=2 | `header.h`, `main.c`
- `xor32` | files=2 | mentions=2 | `header.h`, `main.c`

## Verb Edges

- `byte` --consumes--> `bytes` (strength 1.00)
- `byte` --depends_on--> `bytes` (strength 1.00)
- `byte` --consumes--> `data` (strength 1.00)
- `byte` --depends_on--> `data` (strength 1.00)
- `byte` --consumes--> `decrypt` (strength 1.00)
- `byte` --depends_on--> `decrypt` (strength 1.00)
- `byte` --consumes--> `dword` (strength 1.00)
- `byte` --depends_on--> `dword` (strength 1.00)
- `byte` --consumes--> `else` (strength 1.00)
- `byte` --depends_on--> `else` (strength 1.00)
- `byte` --consumes--> `encrypt` (strength 1.00)
- `byte` --depends_on--> `encrypt` (strength 1.00)
- `byte` --consumes--> `fast` (strength 1.00)
- `byte` --depends_on--> `fast` (strength 1.00)
- `byte` --consumes--> `fluctuate` (strength 1.00)
- `byte` --depends_on--> `fluctuate` (strength 1.00)
- `byte` --consumes--> `fluctuation` (strength 1.00)
- `byte` --depends_on--> `fluctuation` (strength 1.00)
- `byte` --consumes--> `globales` (strength 1.00)
- `byte` --depends_on--> `globales` (strength 1.00)
- `byte` --consumes--> `hook` (strength 1.00)
- `byte` --depends_on--> `hook` (strength 1.00)
- `byte` --consumes--> `hooked` (strength 1.00)
- `byte` --depends_on--> `hooked` (strength 1.00)
- `byte` --consumes--> `ifdef` (strength 1.00)
- `byte` --depends_on--> `ifdef` (strength 1.00)
- `byte` --consumes--> `initialize` (strength 1.00)
- `byte` --depends_on--> `initialize` (strength 1.00)
- `byte` --consumes--> `inject` (strength 1.00)
- `byte` --depends_on--> `inject` (strength 1.00)
- `byte` --consumes--> `log` (strength 1.00)
- `byte` --depends_on--> `log` (strength 1.00)
- `byte` --consumes--> `metadata` (strength 1.00)
- `byte` --depends_on--> `metadata` (strength 1.00)
- `byte` --consumes--> `original` (strength 1.00)
- `byte` --depends_on--> `original` (strength 1.00)
- `byte` --consumes--> `protect` (strength 1.00)
- `byte` --depends_on--> `protect` (strength 1.00)
- `byte` --consumes--> `read` (strength 1.00)
- `byte` --depends_on--> `read` (strength 1.00)
- `byte` --consumes--> `shellcode` (strength 1.00)
- `byte` --depends_on--> `shellcode` (strength 1.00)
- `byte` --consumes--> `size` (strength 1.00)
- `byte` --depends_on--> `size` (strength 1.00)
- `byte` --consumes--> `sleep` (strength 1.00)
- `byte` --depends_on--> `sleep` (strength 1.00)
- `byte` --consumes--> `thread` (strength 1.00)
- `byte` --depends_on--> `thread` (strength 1.00)
- `byte` --consumes--> `trampoline` (strength 1.00)
- `byte` --depends_on--> `trampoline` (strength 1.00)

## Dialectic

- Thesis: `byte` centralizes 2 files; Antithesis: `bytes` pulls 2 files with 2 shared (Jaccard 1.00); Synthesis: should they merge, split by layer, or keep `consumes` explicit?
- Thesis: `byte` centralizes 2 files; Antithesis: `data` pulls 2 files with 2 shared (Jaccard 1.00); Synthesis: should they merge, split by layer, or keep `consumes` explicit?
- Thesis: `byte` centralizes 2 files; Antithesis: `decrypt` pulls 2 files with 2 shared (Jaccard 1.00); Synthesis: should they merge, split by layer, or keep `consumes` explicit?
- Thesis: `byte` centralizes 2 files; Antithesis: `dword` pulls 2 files with 2 shared (Jaccard 1.00); Synthesis: should they merge, split by layer, or keep `consumes` explicit?
- Thesis: `byte` centralizes 2 files; Antithesis: `else` pulls 2 files with 2 shared (Jaccard 1.00); Synthesis: should they merge, split by layer, or keep `consumes` explicit?
- Thesis: `byte` centralizes 2 files; Antithesis: `encrypt` pulls 2 files with 2 shared (Jaccard 1.00); Synthesis: should they merge, split by layer, or keep `consumes` explicit?
- Thesis: `byte` centralizes 2 files; Antithesis: `fast` pulls 2 files with 2 shared (Jaccard 1.00); Synthesis: should they merge, split by layer, or keep `consumes` explicit?
- Thesis: `byte` centralizes 2 files; Antithesis: `fluctuate` pulls 2 files with 2 shared (Jaccard 1.00); Synthesis: should they merge, split by layer, or keep `consumes` explicit?
- Thesis: `byte` centralizes 2 files; Antithesis: `fluctuation` pulls 2 files with 2 shared (Jaccard 1.00); Synthesis: should they merge, split by layer, or keep `consumes` explicit?
- Thesis: `byte` centralizes 2 files; Antithesis: `globales` pulls 2 files with 2 shared (Jaccard 1.00); Synthesis: should they merge, split by layer, or keep `consumes` explicit?
