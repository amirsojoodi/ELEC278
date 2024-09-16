cmake_minimum_required(VERSION 3.20)

project(Tutorial-02 LANGUAGES C)
set(CMAKE_C_STANDARD 11)

add_executable(Tutorial-02-part1 part1.c)
add_executable(Tutorial-02-part2 part2.c)

add_executable(Tutorial-02-part1-solutions part1-solutions.c)
add_executable(Tutorial-02-part2-solutions part2-solutions.c)
