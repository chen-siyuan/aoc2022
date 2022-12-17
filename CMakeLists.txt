cmake_minimum_required(VERSION 3.24)
project(aoc2022)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wshadow -Wpedantic -Werror -fsanitize=address -fsanitize=undefined -O3")

add_executable(a 17/17a.cpp)
add_executable(b 17/17b.cpp)
