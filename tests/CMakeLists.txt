include(FetchContent)

FetchContent_Declare(Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.7.1
  GIT_SHALLOW    TRUE
  SYSTEM)                       # treat Catch2 headers as system: no warnings from them
FetchContent_MakeAvailable(Catch2)

list(APPEND CMAKE_MODULE_PATH "${catch2_SOURCE_DIR}/extras")
include(Catch)

add_executable(ferrex_tests
  test_version.cpp)

target_link_libraries(ferrex_tests PRIVATE
  ferrex::core
  ferrex::warnings
  Catch2::Catch2WithMain)

catch_discover_tests(ferrex_tests)
