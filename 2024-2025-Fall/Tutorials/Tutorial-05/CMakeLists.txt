cmake_minimum_required(VERSION 3.20)

project(Tutorial-05 LANGUAGES C)
set(CMAKE_C_STANDARD 11)

# Build with this to add warning checks
# cmake -D CMAKE_C_FLAGS="-Wall -Wextra" -S . -B build 

add_executable(tutorial_05 src/tutorial_05.c)
# add_executable(tutorial_05_during_class src/tutorial_05_during_class.c)
add_executable(tutorial_05_solution src/tutorial_05_solution.c)
