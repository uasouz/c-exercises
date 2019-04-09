cmake_minimum_required(VERSION 3.12)
project(Exercises C)

set(CMAKE_C_STANDARD 11)

add_executable(ex1 "exercise 1 - array pair sum/main.c")
add_subdirectory(search_algorithms/binary_search)
add_subdirectory(sort_algorithms/insertion_sort)