add_library(some_lib 

"include/node.h"
"include/terminal_node.h"

"include/rule_node.h"
"include/song.h" 
"src/song.cpp" "include/nodes_container.h" "src/nodes_container.cpp" "src/rule_node.cpp" "src/terminal_node.cpp" "include/list_node.h" "src/list_node.cpp")

target_include_directories(some_lib PUBLIC include)

target_link_libraries(
	some_lib
	PUBLIC
	nlohmann_json::nlohmann_json
)