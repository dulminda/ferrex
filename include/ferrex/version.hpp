#pragma once

#include <string_view>

namespace ferrex {

// Human-readable build description, e.g. "ferrex 0.1.0 (clang, optimized)".
// Defined out-of-line so the core library has a real translation unit and
// the build exercises compiling + linking from day one.
[[nodiscard]] std::string_view build_info() noexcept;

}  // namespace ferrex
