cmake_minimum_required(VERSION 3.12)
project(Exercises C)

set(CMAKE_C_STANDARD 11)

add_executable(ex1 "exercise 1 - array pair sum/main.c" data_structures/map/map.c sort_algorithms/quick_sort/quick_sort.c data_structures/git-hashmap/hashmap.c data_structures/git-hashmap/hashmap.h data_structures/git-hashmap/git-compat-util.h data_structures/git-hashmap/banned.h data_structures/git-hashmap/wildmatch.c data_structures/git-hashmap/wildmatch.h data_structures/git-hashmap/compat/bswap.h data_structures/hashmap/hashmap.c data_structures/hashmap/hashmap.h)
add_executable(ex2 "exercise 2 - 0 sum subarray/main.c")

add_subdirectory(search_algorithms/binary_search)
add_subdirectory(sort_algorithms/insertion_sort)
add_subdirectory(sort_algorithms/quick_sort)

add_subdirectory(data_structures/linked_list)