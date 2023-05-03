cmake_minimum_required(VERSION 3.9)

set(project_name AnimeDefenders)
project(${project_name})

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra -Werror -Wpedantic)

set(main_executable ${PROJECT_SOURCE_DIR}/src/main.cpp)
set(include_files 
    ${PROJECT_SOURCE_DIR}/include/A_lib/A.hpp
    ${PROJECT_SOURCE_DIR}/include/AnimeFramework/AnimeFramework.hpp
)
set(include_locations 
    ${PROJECT_SOURCE_DIR}/include/A_lib
    ${PROJECT_SOURCE_DIR}/include/AnimeFramework
)
set(source
    ${PROJECT_SOURCE_DIR}/src/A_lib/A.cpp
    ${PROJECT_SOURCE_DIR}/src/AnimeFramework/AnimeFramework.cpp
)

set(tests_folder ${PROJECT_SOURCE_DIR}/tests)

if(DEBUG OR ENABLE_COVERAGE OR ENABLE_SANITIZERS OR ENABLE_TESTING)
    add_compile_options(-g -O0)   
elseif()
    add_compile_options(-Ofast)
endif()


if(ENABLE_COVERAGE)
    add_compile_options(-fprofile-arcs -ftest-coverage)
endif()

if(ENABLE_CLANG_TIDY AND NOT ENABLE_TESTING AND NOT ENABLE_COVERAGE)
    string(REPLACE "${PROJECT_SOURCE_DIR}" "-I${PROJECT_SOURCE_DIR}" clang_tidy_includes "${include_locations}")
    message("${clang_tidy_includes}")

    find_program(CLANG_TIDY "clang-tidy-15")
    add_custom_target(
        TIDY_TARGET ALL
        COMMAND clang-tidy-15
        --config-file=${PROJECT_SOURCE_DIR}/configs/.clang-tidy 
        ${source} 
        ${main_executable}
        --
        ${clang_tidy_includes}
        -std=c++20
    )
endif()

if(ENABLE_CLANG_FORMAT)
    find_program(CLANG_FORMAT "clang-format")
    add_custom_target(
        FORMAT_CHECK_TARGET ALL
        COMMAND clang-format
        --dry-run 
        --Werror
        -style=file:${PROJECT_SOURCE_DIR}/configs/.clang-format
        ${source}
        ${include_files}
        ${tests_folder}/*.cpp
    )
    add_custom_target(
        FORMAT_TARGET ALL
        COMMAND clang-format
        -i
        --Werror
        -style=file:${PROJECT_SOURCE_DIR}/configs/.clang-format
        ${source}
        ${include_files}
        ${tests_folder}/*.cpp
    )
endif()

if(ENABLE_CPPCHECK)
    find_program(CPPCHECK "cppcheck")
    add_custom_target(
        CPPCHECK_TARGET ALL
        COMMAND cppcheck
        --enable=all 
        --suppress=missingInclude 
        --std=c++20
        ${source}
        ${include_files}
    )
endif()

if(ENABLE_SANITIZERS)
    add_compile_options(-fsanitize=address -fsanitize=leak -fsanitize=undefined)
    add_link_options(-fsanitize=address -fsanitize=leak -fsanitize=undefined) 
endif()

include_directories(${include_locations})
add_executable(${project_name} ${main_executable})

add_custom_target(EXE_TARGET DEPENDS ${project_name})

if(ENABLE_CLANG_FORMAT)
    add_dependencies(${project_name} FORMAT_TARGET)
endif()
if(ENABLE_CLANG_TIDY)
    add_dependencies(${project_name} TIDY_TARGET)
endif()
if(ENABLE_CPPCHECK)
    add_dependencies(${project_name} CPPCHECK_TARGET)
endif()

add_library(${project_name}_lib STATIC ${source})

target_link_libraries(${project_name} ${project_name}_lib)

if(ENABLE_COVERAGE OR ENABLE_TESTING)
    enable_testing()
    add_subdirectory(googletest)
    add_subdirectory(${tests_folder})
    
    find_program(CTEST "ctest")
    add_custom_target(
        TESTS_TARGET ALL 
        COMMAND ctest 
        --output-on-failure
        --test-dir ${PROJECT_BINARY_DIR} 
        DEPENDS tests_list_target
    )

    if(ENABLE_TESTING)
        find_program(VALGRIND "valgrind")
        add_custom_target(
            VALGRIND_TARGET ALL 
            COMMAND valgrind 
            --leak-check=full 
            -s 
            make -C ${PROJECT_BINARY_DIR}/tests test
            DEPENDS tests_list_target
        )
    endif()
endif()

if(ENABLE_COVERAGE)
    target_link_libraries(${project_name} gcov)
endif()
