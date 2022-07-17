add_library(juke_box 
"include/int_node.h"
"include/list_node.h" 
"include/node.h"
"include/juke_box.h"
"include/rule_node.h"
"include/terminal_node.h"

 "src/int_node.cpp"
 "src/list_node.cpp"
 "src/juke_box.cpp" 
 "src/rule_node.cpp" 
 "src/terminal_node.cpp" 
     "include/string_converter.h")

target_include_directories(juke_box PUBLIC include)

include(FetchContent)

FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
    GIT_TAG v3.10.5
)
FetchContent_MakeAvailable(json)

target_link_libraries(
	juke_box
	PUBLIC
	nlohmann_json::nlohmann_json
)