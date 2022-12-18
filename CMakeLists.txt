cmake_minimum_required(VERSION 3.24)
project(aoc2022)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wshadow -Wpedantic -Werror -fsanitize=address -fsanitize=undefined -O3")

add_executable(13a 13/13a.cpp)
add_executable(13b 13/13b.cpp)
add_executable(17b 17/17b.cpp)
add_executable(18b 18/18b.cpp)
add_executable(a 19/19a.cpp)
add_executable(b 19/19b.cpp)
