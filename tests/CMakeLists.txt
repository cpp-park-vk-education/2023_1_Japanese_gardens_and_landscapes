cmake_minimum_required(VERSION 3.9)

add_compile_options(-fprofile-arcs -ftest-coverage)

set(A_test_name A_TESTS)
set(AnimeFramework_test_name ANIME_FRAMEWORK_TESTS)
set(CollisionHandler_test_name COLLISION_HANDLER_TESTS)
set(PhysicsWorld_test_name PHYSICS_WORLD_TESTS)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(AnimeFramework_test ${PROJECT_SOURCE_DIR}/tests/AnimeFramework.cpp)
set(CollisionHandler_test ${PROJECT_SOURCE_DIR}/tests/CollisionHandler.cpp)
set(PhysicsWorld_test ${PROJECT_SOURCE_DIR}/tests/PhysicsWorld.cpp)

add_executable(${AnimeFramework_test_name}_tests_run ${AnimeFramework_test})
add_executable(${CollisionHandler_test_name}_tests_run ${CollisionHandler_test})
add_executable(${PhysicsWorld_test_name}_tests_run ${PhysicsWorld_test})

set(libs gtest_main gtest gmock gcov AnimeDefendersEngine)

target_link_libraries(${AnimeFramework_test_name}_tests_run ${libs})
target_link_libraries(${CollisionHandler_test_name}_tests_run ${libs})
target_link_libraries(${PhysicsWorld_test_name}_tests_run ${libs})

add_custom_target(
    tests_list_target
    DEPENDS
    ${AnimeFramework_test_name}_tests_run
    ${CollisionHandler_test_name}_tests_run
    ${PhysicsWorld_test_name}_tests_run
)

add_test(NAME ${AnimeFramework_test_name} COMMAND ${AnimeFramework_test_name}_tests_run)
add_test(NAME ${CollisionHandler_test_name} COMMAND ${CollisionHandler_test_name}_tests_run)
add_test(NAME ${PhysicsWorld_test_name} COMMAND ${PhysicsWorld_test_name}_tests_run)