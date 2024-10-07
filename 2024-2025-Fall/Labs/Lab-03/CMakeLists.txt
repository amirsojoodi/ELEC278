cmake_minimum_required(VERSION 3.20)
project(Lab3 C)

# Add the executable
add_executable(lab3 main.c stack.c)

# Include directories for header files
target_include_directories(lab3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
