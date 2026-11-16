# Roadmap

| Phase | Scope | Status |
|---|---|---|
| 0 | Skeleton: CMake presets, sanitizers, Catch2, Google Benchmark, CI, clang-format/tidy | 🔄 in progress |
| 1 | Domain model: strong types, fixed-point prices, price-time matching, exception guarantees | ⏳ |
| 2 | Memory: pools, intrusive price levels, zero hot-path allocations | ⏳ |
| 3 | Generics: concepts, policy-based matching, static dispatch | ⏳ |
| 4 | Binary protocol: zero-copy codec, fuzzing | ⏳ |
| 5 | Concurrency: SPSC rings, sharded matching, wait strategies | ⏳ |
| 6 | Networking: epoll/kqueue reactor, C++20 coroutines, UDP market data | ⏳ |
| 7 | Persistence: WAL, snapshots, deterministic replay | ⏳ |
| 8 | Hardening: simulation testing, profiling, docs | ⏳ |

Full plan with reading list: `~/cpp-study/project-plan-exchange.md`.
