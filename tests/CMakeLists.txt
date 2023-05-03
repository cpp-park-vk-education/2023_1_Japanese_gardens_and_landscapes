cmake_minimum_required(VERSION 3.9)

add_compile_options(-fprofile-arcs -ftest-coverage)

set(A_test_name A_TESTS)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(A_tests ${PROJECT_SOURCE_DIR}/tests/A.cpp)

add_executable(${A_test_name}_tests_run ${A_tests})

set(libs ${project_name}_lib gtest_main gtest gmock gcov)

target_link_libraries(${A_test_name}_tests_run ${libs})

add_custom_target(
    tests_list_target 
    DEPENDS 
    ${A_test_name}_tests_run
)

add_test(NAME ${A_test_name} COMMAND ${A_test_name}_tests_run)
