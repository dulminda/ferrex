#include "ferrex/version.hpp"

// FERREX_VERSION_STRING comes from project(VERSION ...) in CMakeLists.txt,
// so the version lives in exactly one place.
#ifndef FERREX_VERSION_STRING
#error "FERREX_VERSION_STRING must be defined by the build system"
#endif

#if defined(__clang__)
#define FERREX_COMPILER "clang"
#elif defined(__GNUC__)
#define FERREX_COMPILER "gcc"
#else
#define FERREX_COMPILER "unknown"
#endif

#if defined(NDEBUG)
#define FERREX_BUILD "optimized"
#else
#define FERREX_BUILD "debug"
#endif

namespace ferrex {

std::string_view build_info() noexcept {
    return "ferrex " FERREX_VERSION_STRING " (" FERREX_COMPILER ", " FERREX_BUILD ")";
}

}  // namespace ferrex
