cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)

include_directories(".")
include_directories("..")

#94
add_executable(94 0094_Binary_Tree_Inorder_Traversal/main.cpp binary_tree.cpp)

#98
add_executable(98 0098_Validate_Binary_Search_Tree/main.cpp binary_tree.cpp)

#102
add_executable(102 0102_Binary_Tree_Level_Order_Traversal/main.cpp binary_tree.cpp)

#144
add_executable(144 0144_Binary_Tree_Preorder_Traversal/main.cpp binary_tree.cpp)


#145
add_executable(145 0145_Binary_Tree_Postorder_Traversal/main.cpp binary_tree.cpp)

#226
add_executable(226 0226_Invert_Binary_Tree/main.cpp binary_tree.cpp)

#606
add_executable(606 0606_Construct_String_from_Binary_Tree/main.cpp binary_tree.cpp)
