cmake_minimum_required(VERSION 3.12)
project(Exercises C)

set(CMAKE_C_STANDARD 11)

add_executable(ex1 "exercise 1 - array pair sum/main.c" data_structures/map/map.c sort_algorithms/quick_sort/quick_sort.c data_structures/hashmap/hashmap.c data_structures/hashmap/hashmap.h data_structures/hashmap/git-compat-util.h data_structures/hashmap/banned.h data_structures/hashmap/wildmatch.c data_structures/hashmap/wildmatch.h data_structures/hashmap/compat/bswap.h)
add_executable(ex2 "exercise 2 - 0 sum subarray/main.c")

add_subdirectory(search_algorithms/binary_search)
add_subdirectory(sort_algorithms/insertion_sort)
add_subdirectory(sort_algorithms/quick_sort)