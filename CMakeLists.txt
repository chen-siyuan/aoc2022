cmake_minimum_required(VERSION 3.24)
project(aoc2022)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wshadow -Wpedantic -Werror -fsanitize=address -fsanitize=undefined")

add_executable(a 15/15a.cpp)
add_executable(b 15/15b.cpp)
