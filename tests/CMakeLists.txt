cmake_minimum_required(VERSION 3.9)

add_compile_options(-fprofile-arcs -ftest-coverage)

set(A_test_name A_TESTS)
set(AnimeFramework_test_name ANIME_FRAMEWORK_TESTS)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(AnimeFramework_test ${PROJECT_SOURCE_DIR}/tests/AnimeFramework.cpp)

add_executable(${AnimeFramework_test_name}_tests_run ${AnimeFramework_test})

set(libs ${project_name}_lib gtest_main gtest gmock gcov)

target_link_libraries(${AnimeFramework_test_name}_tests_run ${libs})

add_custom_target(
    tests_list_target 
    DEPENDS 
    ${AnimeFramework_test_name}_tests_run
)

add_test(NAME ${AnimeFramework_test_name} COMMAND ${AnimeFramework_test_name}_tests_run)
