# ferrex

A low-latency exchange written in modern C++: price-time matching engine,
lock-free sharded pipeline, coroutine-based TCP gateway, UDP market data, and
event-sourced recovery.

> **Status:** Phase 0 — skeleton and tooling. See [ROADMAP.md](ROADMAP.md).

## Build

Requirements: CMake ≥ 3.25, a C++23 compiler (Clang 17+ / GCC 14+).

```bash
cmake --preset debug          # configure
cmake --build --preset debug  # build
ctest --preset debug          # test
```

| Preset    | Purpose                                     |
|-----------|---------------------------------------------|
| `debug`   | Day-to-day development                      |
| `release` | `-O3` + LTO, used for all benchmark numbers |
| `asan`    | AddressSanitizer + UndefinedBehaviorSanitizer |
| `tsan`    | ThreadSanitizer                             |

Benchmarks (release only):

```bash
cmake --preset release && cmake --build --preset release
./build/release/bench/ferrex_bench
```

## Layout

```
include/ferrex/   public headers
src/              library implementation (ferrex::core)
apps/ferrexd/     the exchange daemon
tests/            Catch2 unit tests
bench/            Google Benchmark micro-benchmarks
cmake/            warning + sanitizer modules
docs/             architecture, ADRs, performance results
```

## Docs

- [Architecture](docs/ARCHITECTURE.md)
- [Decision records](docs/adr/)
- [Performance results](docs/perf.md)
