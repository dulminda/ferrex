cmake_minimum_required(VERSION 3.25)

project(ferrex
  VERSION 0.1.0
  DESCRIPTION "Low-latency exchange: matching engine, gateway, market data"
  LANGUAGES CXX)

# ---- Global settings ---------------------------------------------------------
set(CMAKE_CXX_STANDARD 23)            # see docs/adr/0002-language-standard.md
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)          # -std=c++23, not gnu++23
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # for clangd / clang-tidy

if(PROJECT_IS_TOP_LEVEL AND NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# ---- Options -----------------------------------------------------------------
option(FERREX_WARNINGS_AS_ERRORS "Treat compiler warnings as errors" ON)
option(FERREX_BUILD_TESTS        "Build unit tests"                  ON)
option(FERREX_BUILD_BENCHMARKS   "Build Google Benchmark targets"    ON)
set(FERREX_SANITIZERS "" CACHE STRING
    "Semicolon list of sanitizers, e.g. 'address;undefined' or 'thread'")

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
include(CompilerWarnings)
include(Sanitizers)

# ---- Core library ------------------------------------------------------------
add_library(ferrex_core
  src/version.cpp)
add_library(ferrex::core ALIAS ferrex_core)

target_include_directories(ferrex_core
  PUBLIC  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)
target_compile_features(ferrex_core PUBLIC cxx_std_23)
target_compile_definitions(ferrex_core
  PRIVATE FERREX_VERSION_STRING="${PROJECT_VERSION}")
target_link_libraries(ferrex_core
  PRIVATE ferrex::warnings
  PUBLIC  ferrex::sanitizers)

# ---- Executables -------------------------------------------------------------
add_executable(ferrexd apps/ferrexd/main.cpp)
target_link_libraries(ferrexd PRIVATE ferrex::core ferrex::warnings)

# ---- Tests & benchmarks ------------------------------------------------------
if(FERREX_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()

if(FERREX_BUILD_BENCHMARKS)
  add_subdirectory(bench)
endif()
