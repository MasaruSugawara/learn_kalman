cmake_minimum_required(VERSION 3.10)
project(learn_kalman)

set(CMAKE_CXX_STANDARD 17)
set(MY_LIB_SRCS 
  src/kalman.cpp
)
set(MY_LIB_INCLUDE_DIRS
  /usr/include/eigen3
  include
)
set(TESTER_LIB_SRCS
  tests/interactive_tester.cpp
)

add_library(kalman SHARED ${MY_LIB_SRCS})
target_include_directories(kalman PUBLIC ${MY_LIB_INCLUDE_DIRS})

add_executable(kalman_app src/main.cpp)
target_link_libraries(kalman_app PRIVATE kalman)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(libtester SHARED ${TESTER_LIB_SRCS})
target_include_directories(libtester PUBLIC ${MY_LIB_INCLUDE_DIRS})
add_executable(unit_test tests/unit_test.cpp)
target_link_libraries(unit_test PRIVATE libtester gtest_main)
