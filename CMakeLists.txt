cmake_minimum_required(VERSION 3.23)
project(aoc2022)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wshadow -Wpedantic -Werror -fsanitize=address -fsanitize=undefined -DSHAWNA")

add_executable(1a 1/1a.cpp)
add_executable(1b 1/1b.cpp)
add_executable(2a 2/2a.cpp)
add_executable(2b 2/2b.cpp)
