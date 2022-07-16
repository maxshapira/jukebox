add_library(some_lib 
"include/int_node.h"
"include/list_node.h" 
"include/node.h"
"include/nodes_container.h"
"include/rule_node.h"
"include/terminal_node.h"

 "src/int_node.cpp"
 "src/list_node.cpp"
 "src/nodes_container.cpp" 
 "src/rule_node.cpp" 
 "src/terminal_node.cpp" 
   )

target_include_directories(some_lib PUBLIC include)

include(FetchContent)

FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
    GIT_TAG v3.10.5
)
FetchContent_MakeAvailable(json)

target_link_libraries(
	some_lib
	PUBLIC
	nlohmann_json::nlohmann_json
)