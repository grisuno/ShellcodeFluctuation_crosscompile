# Gotchas

## God Nodes (high connectivity)

These files have the most connections. Changes here have high blast radius.

- `header.h` (score: 3.80, imported by 1 files)
- `main.c` (score: 3.30)
- `app.py` (score: 0.00)
- `install.sh` (score: 0.00)

## Blast Radius (change impact)

Editing these files can break the listed number of dependents. Run their tests after any change.

- `header.h` -- 1 direct, 1 total dependents

## Hotspots (complexity + centrality)

- `header.h` -- complexity: 1.0, centrality: 1.0, combined: 1.0
- `main.c` -- complexity: 0.7, centrality: 0.3, combined: 0.5
- `app.py` -- complexity: 0.0, centrality: 0.1, combined: 0.1
- `install.sh` -- complexity: 0.0, centrality: 0.0, combined: 0.0

## Dataflow Issues (INFERRED, review each lead)

- `main.c:236` `readShellcode` [UNCHECKED_ALLOC] `buf`: Result of allocator stored in `buf` is never checked against NULL.
