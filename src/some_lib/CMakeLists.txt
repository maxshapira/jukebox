add_library(some_lib 
"src/some_class.cpp"
"include/node.h"
"include/terminal_node.h"
"src/node.cpp"
"include/rule_node.h"
"include/song.h" 
"src/song.cpp")

target_include_directories(some_lib PUBLIC include)

target_link_libraries(
	some_lib
	PUBLIC
	nlohmann_json::nlohmann_json
)