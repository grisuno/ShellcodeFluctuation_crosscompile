# Concepts

Second-brain semantic layer: nouns map atomically to file sets (EXTRACTED); verbs aggregate structural edges (INFERRED).

| Concept | Files | Mentions | Top Files |
|---------|-------|----------|-----------|
| `shellcode` | 2 | 28 | `header.h`, `main.c` |
| `fluctuation` | 2 | 27 | `header.h`, `main.c` |
| `size` | 2 | 27 | `header.h`, `main.c` |
| `data` | 2 | 18 | `header.h`, `main.c` |
| `sleep` | 2 | 15 | `header.h`, `main.c` |
| `bytes` | 2 | 11 | `header.h`, `main.c` |
| `read` | 2 | 10 | `header.h`, `main.c` |
| `log` | 2 | 9 | `header.h`, `main.c` |
| `protect` | 2 | 9 | `header.h`, `main.c` |
| `thread` | 2 | 9 | `header.h`, `main.c` |
| `dword` | 2 | 8 | `header.h`, `main.c` |
| `fluctuate` | 2 | 7 | `header.h`, `main.c` |
| `hook` | 2 | 7 | `header.h`, `main.c` |
| `hooked` | 2 | 7 | `header.h`, `main.c` |
| `original` | 2 | 7 | `header.h`, `main.c` |
| `trampoline` | 2 | 7 | `header.h`, `main.c` |
| `uptr` | 2 | 7 | `header.h`, `main.c` |
| `byte` | 2 | 5 | `header.h`, `main.c` |
| `decrypt` | 2 | 5 | `header.h`, `main.c` |
| `type` | 2 | 5 | `header.h`, `main.c` |
| `else` | 2 | 4 | `header.h`, `main.c` |
| `encrypt` | 2 | 4 | `header.h`, `main.c` |
| `fast` | 2 | 4 | `header.h`, `main.c` |
| `metadata` | 2 | 4 | `header.h`, `main.c` |
| `globales` | 2 | 3 | `header.h`, `main.c` |
| `inject` | 2 | 3 | `header.h`, `main.c` |
| `ifdef` | 2 | 2 | `header.h`, `main.c` |
| `initialize` | 2 | 2 | `header.h`, `main.c` |
| `win64` | 2 | 2 | `header.h`, `main.c` |
| `xor32` | 2 | 2 | `header.h`, `main.c` |

## Verb Edges

| Source | Verb | Target | Strength |
|--------|------|--------|----------|
| `byte` | `consumes` | `bytes` | 1.00 |
| `byte` | `depends_on` | `bytes` | 1.00 |
| `byte` | `consumes` | `data` | 1.00 |
| `byte` | `depends_on` | `data` | 1.00 |
| `byte` | `consumes` | `decrypt` | 1.00 |
| `byte` | `depends_on` | `decrypt` | 1.00 |
| `byte` | `consumes` | `dword` | 1.00 |
| `byte` | `depends_on` | `dword` | 1.00 |
| `byte` | `consumes` | `else` | 1.00 |
| `byte` | `depends_on` | `else` | 1.00 |
| `byte` | `consumes` | `encrypt` | 1.00 |
| `byte` | `depends_on` | `encrypt` | 1.00 |
| `byte` | `consumes` | `fast` | 1.00 |
| `byte` | `depends_on` | `fast` | 1.00 |
| `byte` | `consumes` | `fluctuate` | 1.00 |
| `byte` | `depends_on` | `fluctuate` | 1.00 |
| `byte` | `consumes` | `fluctuation` | 1.00 |
| `byte` | `depends_on` | `fluctuation` | 1.00 |
| `byte` | `consumes` | `globales` | 1.00 |
| `byte` | `depends_on` | `globales` | 1.00 |
| `byte` | `consumes` | `hook` | 1.00 |
| `byte` | `depends_on` | `hook` | 1.00 |
| `byte` | `consumes` | `hooked` | 1.00 |
| `byte` | `depends_on` | `hooked` | 1.00 |
| `byte` | `consumes` | `ifdef` | 1.00 |
| `byte` | `depends_on` | `ifdef` | 1.00 |
| `byte` | `consumes` | `initialize` | 1.00 |
| `byte` | `depends_on` | `initialize` | 1.00 |
| `byte` | `consumes` | `inject` | 1.00 |
| `byte` | `depends_on` | `inject` | 1.00 |
| `byte` | `consumes` | `log` | 1.00 |
| `byte` | `depends_on` | `log` | 1.00 |
| `byte` | `consumes` | `metadata` | 1.00 |
| `byte` | `depends_on` | `metadata` | 1.00 |
| `byte` | `consumes` | `original` | 1.00 |
| `byte` | `depends_on` | `original` | 1.00 |
| `byte` | `consumes` | `protect` | 1.00 |
| `byte` | `depends_on` | `protect` | 1.00 |
| `byte` | `consumes` | `read` | 1.00 |
| `byte` | `depends_on` | `read` | 1.00 |
| `byte` | `consumes` | `shellcode` | 1.00 |
| `byte` | `depends_on` | `shellcode` | 1.00 |
| `byte` | `consumes` | `size` | 1.00 |
| `byte` | `depends_on` | `size` | 1.00 |
| `byte` | `consumes` | `sleep` | 1.00 |
| `byte` | `depends_on` | `sleep` | 1.00 |
| `byte` | `consumes` | `thread` | 1.00 |
| `byte` | `depends_on` | `thread` | 1.00 |
| `byte` | `consumes` | `trampoline` | 1.00 |
| `byte` | `depends_on` | `trampoline` | 1.00 |

## Dialectic Prompts

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
