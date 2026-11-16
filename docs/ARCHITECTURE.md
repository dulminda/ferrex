# Architecture

*Target design; filled in phase by phase.*

```
 clients ──TCP──► Gateway (reactor + coroutines)
                     │ SPSC ring per shard
                     ▼
              Matching shard (1 thread, pinned)
              ├─ OrderBook per symbol
              ├─ Journal ──► WAL ──► replay / recovery
              └─ Market-data ring ──► Publisher ──UDP multicast──►
```

## Principles
1. **Single writer per order book.** Shards own symbols; books need no locks.
2. **No allocation on the hot path** after warm-up.
3. **Deterministic core.** Engine output is a pure function of the input log.
4. **Measure, don't guess.** Every performance claim links to a benchmark in `docs/perf.md`.
