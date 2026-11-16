include(FetchContent)

set(BENCHMARK_ENABLE_TESTING        OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_GTEST_TESTS    OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_INSTALL        OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_WERROR         OFF CACHE BOOL "" FORCE)

FetchContent_Declare(benchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG        v1.9.1
  GIT_SHALLOW    TRUE
  SYSTEM)
FetchContent_MakeAvailable(benchmark)

add_executable(ferrex_bench
  bench_baseline.cpp)

target_link_libraries(ferrex_bench PRIVATE
  ferrex::core
  ferrex::warnings
  benchmark::benchmark_main)
