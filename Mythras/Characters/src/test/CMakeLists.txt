
add_executable(
  roll_test
  roll_test.cc ../Roll.cpp
)
target_link_libraries(
  roll_test
  gtest_main
)
gtest_discover_tests(roll_test)
