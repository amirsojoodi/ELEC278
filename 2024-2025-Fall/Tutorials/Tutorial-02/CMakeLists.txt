cmake_minimum_required(VERSION 3.20)

project(Tutorial-02 LANGUAGES C)
set(CMAKE_C_STANDARD 11)

add_executable(tutorial_02_part1 src/part1.c)
add_executable(tutorial_02_part2 src/part2.c)
add_executable(tutorial_02_part1_during_class src/part1_during_class.c)
add_executable(tutorial_02_part2_during_class src/part2_during_class.c)
add_executable(tutorial_02_part1_solutions src/part1_solutions.c)
add_executable(tutorial_02_part2_solutions src/part2_solutions.c)
