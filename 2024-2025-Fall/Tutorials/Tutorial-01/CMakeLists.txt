cmake_minimum_required(VERSION 3.15)

project(Tutorial-01 LANGUAGES C)
set(CMAKE_C_STANDARD 11)

add_executable(tutorial_01_part1 src/part1.c)
add_executable(tutorial_01_part2 src/part2.c)
add_executable(tutorial_01_part2_during_class src/part2_during_class.c)
add_executable(tutorial_01_part2_solutions src/part2_solutions.c)
