include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(app_test "juke_box_test.cpp")

target_link_libraries(app_test
 PRIVATE
  GTest::GTest
  juke_box)

add_test(app_gtests app_test)
