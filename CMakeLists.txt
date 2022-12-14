cmake_minimum_required(VERSION 3.23)
project(aoc2022)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wshadow -Wpedantic -Werror -fsanitize=address -fsanitize=undefined -DSHAWNA")

add_executable(a 14/14a.cpp)
add_executable(b 14/14b.cpp)
