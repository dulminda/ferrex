// Baseline: the "naive order book" data structure, a std::map keyed by price.
// Phase 2 replaces it with intrusive, pool-allocated levels; keeping this
// benchmark lets you show the before/after numbers in docs/perf.md.

#include <benchmark/benchmark.h>

#include <cstdint>
#include <map>
#include <random>
#include <vector>

namespace {

std::vector<std::int64_t> make_prices(std::size_t n) {
    std::mt19937_64 rng{42};  // fixed seed: benchmarks must be reproducible
    std::uniform_int_distribution<std::int64_t> dist{9'000, 11'000};
    std::vector<std::int64_t> prices(n);
    for (auto& p : prices) {
        p = dist(rng);
    }
    return prices;
}

void BM_StdMapInsertErase(benchmark::State& state) {
    const auto n = static_cast<std::size_t>(state.range(0));
    const auto prices = make_prices(n);

    for (auto _ : state) {
        std::map<std::int64_t, std::int64_t> levels;
        for (const auto p : prices) {
            levels[p] += 100;
        }
        for (const auto p : prices) {
            levels.erase(p);
        }
        benchmark::DoNotOptimize(levels);
    }
    state.SetItemsProcessed(state.iterations() * static_cast<std::int64_t>(n) * 2);
}

BENCHMARK(BM_StdMapInsertErase)->RangeMultiplier(8)->Range(64, 32'768);

}  // namespace
