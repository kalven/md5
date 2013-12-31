cmake_minimum_required (VERSION 2.6)

if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_CLANG)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -std=c++0x -Wall")
endif()

add_executable(md5sum md5.cpp sum.cpp)
