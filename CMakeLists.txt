cmake_minimum_required(VERSION 3.9)

set(project_name AnimeDefenders)
project(${project_name})

set(CMAKE_CXX_STANDARD 23)
add_compile_options(-Wall -Wextra -Werror -Wpedantic)

set(main_executable src/main.cpp)

set(include_files
    include/AnimeFramework/AnimeFramework.hpp
    include/AnimeFramework/Component.hpp
    include/AnimeFramework/ComponentManager.hpp
    include/AnimeFramework/Entity.hpp
    include/AnimeFramework/Event.hpp
    include/AnimeFramework/EventManager.hpp
    include/AnimeFramework/GameLoop.hpp
    include/AnimeFramework/InputManager.hpp
    include/AnimeFramework/MemoryMaster.hpp
    include/AnimeFramework/Scene.hpp
    include/AnimeFramework/SceneManager.hpp
    include/AudioSystem/AudioSource.hpp
    include/AudioSystem/AudioSystem.hpp
    include/CameraComponent/Camera.hpp
    include/CameraComponent/CameraSystem.hpp
    include/FileSystem/FileSystem.hpp
    include/Graphics/Animaton.hpp
    include/Graphics/Color.hpp
    include/Graphics/IDrawTextureWrapper.hpp
    include/Graphics/ITrasnposeMathWrapper.hpp
    include/Graphics/IUiContextWrapper.hpp
    include/Graphics/IWindow.hpp
    include/Graphics/Renderer.hpp
    include/Graphics/Texture.hpp
    include/Logger/Logger.hpp
    include/Math/Coords2d.hpp
    include/Math/Graph.hpp
    include/Math/Matrix2d.hpp
    include/Math/Vector2.hpp
    include/OpenAlDependency/AudioPlayWrapper.hpp
    include/OpenGlDependency/DrawTextureWrapper.hpp
    include/OpenGlDependency/TransposeMathWrapper.hpp
    include/OpenGlDependency/UiContextWrapper.hpp
    include/OpenGlDependency/Window.hpp
    include/Physics/Body.hpp
    include/Physics/BodyDefinition.hpp
    include/Physics/CollisionHandler.hpp
    include/Physics/Manifold.hpp
    include/Physics/PhysicsSystem.hpp
    include/Physics/PhysicsWorld.hpp
    include/Physics/Shape.hpp
    include/SpriteComponent/Sprite.hpp
    include/SpriteComponent/SpriteSystem.hpp
    include/Systems/ISystem.hpp
    include/Systems/SystemMananger.hpp
    include/UiColorElementComponent/UiColorElement.hpp
    include/UiColorElementComponent/UiColorElementSystem.hpp
    include/UiElementComponent/UiElement.hpp
    include/UiElementComponent/UiElementSystem.hpp
    include/UiLabelComponent/UiLabel.hpp
    include/UiLabelComponent/UiLabelSystem.hpp
    include/UiTextureElementComponent/UiTextureElement.hpp
    include/UiTextureElementComponent/UiTextureElementSystem.hpp
)
set(include_locations
    include/AnimeFramework
    include/AudioSystem
    include/CameraComponent
    include/FileSystem
    include/Graphics
    include/Logger
    include/Math
    include/OpenAlDependency
    include/OpenGlDependency
    include/Physics
    include/SpriteComponent
    include/Systems
    include/UiColorElementComponent
    include/UiElementComponent
    include/UiLabelComponent
    include/UiTextureElementComponent
)
set(source
    src/AnimeFramework/AnimeFramework.cpp
    src/AnimeFramework/ComponentManager.cpp
    src/AnimeFramework/Entity.cpp
    src/AnimeFramework/EventManager.cpp
    src/AnimeFramework/GameLoop.cpp
    src/AnimeFramework/InputManager.cpp
    src/AnimeFramework/Scene.cpp
    src/AnimeFramework/SceneManager.cpp
    src/AudioSystem/AudioSource.cpp
    src/AudioSystem/AudioSystem.cpp
    src/CameraComponent/Camera.cpp
    src/CameraComponent/CameraSystem.cpp
    src/FileSystem/FileSystem.cpp
    src/Graphics/Renderer.cpp
    src/Logger/Logger.cpp
    src/Math/Coords2d.cpp
    src/Math/Graph.cpp
    src/Math/Matrix2d.cpp
    src/Math/Vector2.cpp
    src/OpenAlDependency/AudioPlayWrapper.cpp
    src/OpenGlDependency/DrawTextureWrapper.cpp
    src/OpenGlDependency/TransposeMathWrapper.cpp
    src/OpenGlDependency/UiContextWrapper.cpp
    src/OpenGlDependency/Window.cpp
    src/Physics/Body.cpp
    src/Physics/BodyDefinition.cpp
    src/Physics/CollisionHandler.cpp
    src/Physics/PhysicsSystem.cpp
    src/Physics/PhysicsWorld.cpp
    src/Physics/Shape.cpp
    src/SpriteComponent/Sprite.cpp
    src/SpriteComponent/SpriteSystem.cpp
    src/Systems/SystemManager.cpp
    src/UiColorElementComponent/UiColorElement.cpp
    src/UiColorElementComponent/UiColorElementSystem.cpp
    src/UiElementComponent/UiElement.cpp
    src/UiElementComponent/UiElementSystem.cpp
    src/UiLabelComponent/UiLabel.cpp
    src/UiLabelComponent/UiLabelSystem.cpp
    src/UiTextureElementComponent/UiTextureElement.cpp
    src/UiTextureElementComponent/UiTextureElementSystem.cpp
)

set(tests_folder tests)

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
        --config-file=configs/.clang-tidy
        ${source}
        ${main_executable}
        --
        ${clang_tidy_includes}
        -std=c++23
    )
endif()

if(ENABLE_CLANG_FORMAT)
    find_program(CLANG_FORMAT "clang-format")
    add_custom_target(
        FORMAT_CHECK_TARGET ALL
        COMMAND clang-format
        --dry-run
        --Werror
        -style=file:configs/.clang-format
        ${source}
        ${include_files}
        ${tests_folder}/*.cpp
    )
    add_custom_target(
        FORMAT_TARGET ALL
        COMMAND clang-format
        -i
        --Werror
        -style=file:configs/.clang-format
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
        --std=c++23
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
