# Interface target carrying the project's warning flags.
# Link it PRIVATE to our own targets only, so third-party code
# (Catch2, Google Benchmark) is not held to the same bar.

add_library(ferrex_warnings INTERFACE)
add_library(ferrex::warnings ALIAS ferrex_warnings)

set(_ferrex_common_warnings
  -Wall
  -Wextra
  -Wpedantic
  -Wshadow                 # a variable hides one from an outer scope
  -Wconversion             # implicit narrowing (critical for prices/quantities)
  -Wsign-conversion
  -Wold-style-cast
  -Wcast-align
  -Wnon-virtual-dtor
  -Woverloaded-virtual
  -Wnull-dereference
  -Wdouble-promotion
  -Wformat=2
  -Wimplicit-fallthrough
  -Wunused)

set(_ferrex_gcc_warnings
  -Wduplicated-cond
  -Wduplicated-branches
  -Wlogical-op
  -Wuseless-cast)

target_compile_options(ferrex_warnings INTERFACE
  ${_ferrex_common_warnings}
  $<$<CXX_COMPILER_ID:GNU>:${_ferrex_gcc_warnings}>
  $<$<BOOL:${FERREX_WARNINGS_AS_ERRORS}>:-Werror>)
