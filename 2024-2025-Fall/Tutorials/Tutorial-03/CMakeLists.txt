cmake_minimum_required(VERSION 3.20)

project(Tutorial-03 LANGUAGES C)
set(CMAKE_C_STANDARD 11)

# Build with this to add warning checks
# cmake -D CMAKE_C_FLAGS="-Wall -Wextra" -S . -B build 

add_executable(tutorial_03 src/tutorial_03.c)
add_executable(tutorial_03_during_class src/tutorial_03_during_class.c)
add_executable(tutorial_03_solution src/tutorial_03_solution.c)
