add_library(some_lib "src/some_class.cpp" "include/node.h" "include/terminal_node.h" "src/node.cpp")

target_include_directories(some_lib PUBLIC include)