cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)

include_directories(".")
include_directories("utils")

#001
add_executable(0001_ _bynum/001/two_sum.cpp)

#007
add_executable(0007_ _bynum/007/reverse_integer.cpp)

#009
add_executable(0009_ _bynum/009/palindrone_number.cpp)

#014
add_executable(0014_ _bynum/014/longest_common_prefix.cpp)

#022
add_executable(22_ _bynum/22/Generate_Parentheses.cpp)

#067
add_executable(0067_ _bynum/067/add_binary.cpp)

#069
add_executable(0069_ _bynum/069/sqrt.cpp)

#112
add_executable(0112_ _bynum/112/path_sum.cpp)

#278
add_executable(0278_ _bynum/278/first_bad_version.cpp)

add_subdirectory(bs)
add_subdirectory(sum)
add_subdirectory(number)
add_subdirectory(backtracking)
add_subdirectory(binary_tree)
add_subdirectory(string)
add_subdirectory(array)
add_subdirectory(matrix)
add_subdirectory(math)
add_subdirectory(link_list)
add_subdirectory(set&map)
add_subdirectory(stack&queue)
add_subdirectory(dynamic_programming)
add_subdirectory(usefull)
add_subdirectory(greedy)
add_subdirectory(design)