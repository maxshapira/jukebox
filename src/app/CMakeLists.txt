add_executable(app main.cpp "../some_lib/include/file_parser.h" "../some_lib/src/file_parser.cpp")

target_link_libraries(
	app
	PUBLIC
	some_lib
)