#include "ferrex/version.hpp"

#include <format>
#include <string_view>

// FERREX_VERSION_STRING comes from project(VERSION ...) in CMakeLists.txt,
// so the version lives in exactly one place.
#ifndef FERREX_VERSION_STRING
#error "FERREX_VERSION_STRING must be defined by the build system"
#endif

namespace ferrex {

namespace {

constexpr std::string_view kVersionString = FERREX_VERSION_STRING;

#if defined(__clang__)
constexpr std::string_view kCompiler = "clang";
#elif defined(__GNUC__)
constexpr std::string_view kCompiler = "gcc";
#else
constexpr std::string_view kCompiler = "unknown";
#endif

#if defined(NDEBUG)
constexpr std::string_view kBuild = "optimized";
#else
constexpr std::string_view kBuild = "debug";
#endif

}  // namespace

std::string build_info() {
    return std::format("ferrex {} ({}, {})", kVersionString, kCompiler, kBuild);
}

}  // namespace ferrex
