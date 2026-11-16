# ADR 0002: Target C++23

**Status:** Accepted

## Context
The design relies on C++20 features (concepts, coroutines, `std::span`,
`std::jthread`, `std::bit_cast`) and wants `std::expected` for error handling
on the hot path, which is C++23.

## Decision
Compile with `-std=c++23` (no GNU extensions). Minimum compilers: GCC 14,
Clang 17 / Apple Clang 17.

## Consequences
- `std::expected` available without a third-party shim.
- Older toolchains are unsupported, which is acceptable for a new project.

## Alternatives considered
- **C++20 + `tl::expected`:** wider compiler support, but an extra dependency
  and a less idiomatic result.
