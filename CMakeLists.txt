cmake_minimum_required(VERSION 3.14)
project(cross_dot)

set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(inc)

add_library(
  cross_dot-lib
  src/cross_dot.cpp
)

add_executable(
  cross_dot-uts
  tests/cross_dot_tests.cpp
)

target_link_libraries(
  cross_dot-uts
  cross_dot-lib
  gmock_main
)

include(GoogleTest)
gtest_discover_tests(cross_dot-uts)
