cmake_minimum_required(VERSION 3.9)

set(project_name AnimeDefendersEngine)
project(${project_name})

set(CMAKE_CXX_STANDARD 20)

set(include_files
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AnimeFramework/AnimeFramework.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AnimeFramework/Component.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AnimeFramework/BaseComponent.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AnimeFramework/ComponentManager.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AnimeFramework/Entity.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AnimeFramework/IEntityCreator.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AnimeFramework/Event.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AnimeFramework/EventManager.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AnimeFramework/GameLoop.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AnimeFramework/InputManager.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AnimeFramework/MemoryMaster.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AnimeFramework/Scene.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AnimeFramework/SceneLoader.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AnimeFramework/SceneManager.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AudioSystem/AudioSource.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AudioSystem/AudioSystem.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/CameraComponent/Camera.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/CameraComponent/CameraSystem.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/FileSystem/FileSystem.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/FileSystem/TableReader.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Graphics/Color.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Graphics/IDrawTextureWrapper.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Graphics/IUiContextWrapper.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Graphics/IWindow.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Graphics/Renderer.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Graphics/Texture.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Logger/Logger.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Math/Coords2d.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Math/Coords3d.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Math/Graph.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Math/Matrix2d.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Math/Transpose.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Math/Vector2.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/OpenAlDependency/AudioPlayWrapper.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/OpenGlDependency/DrawTextureWrapper.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/OpenGlDependency/TransposeMathWrapper.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/OpenGlDependency/UiContextWrapper.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/OpenGlDependency/Window.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Physics/Body.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Physics/BodyDefinition.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Physics/CollisionHandler.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Physics/ContactEvent.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Physics/ICollisionHandler.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Physics/Manifold.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Physics/PhysicsSystem.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Physics/PhysicsWorld.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Physics/Shape.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/SpriteComponent/Sprite.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/SpriteComponent/SpriteSystem.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Systems/ISystem.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/UiColorElementComponent/UiColorElement.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/UiColorElementComponent/UiColorElementSystem.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/UiElementComponent/UiElement.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/UiElementComponent/UiElementSystem.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/UiLabelComponent/UiLabel.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/UiLabelComponent/UiLabelSystem.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/UiTextureElementComponent/UiTextureElement.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/UiTextureElementComponent/UiTextureElementSystem.hpp
)

set(include_locations
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AnimeFramework
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AudioSystem
    ${CMAKE_CURRENT_SOURCE_DIR}/include/CameraComponent
    ${CMAKE_CURRENT_SOURCE_DIR}/include/FileSystem
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Graphics
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Logger
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Math
    ${CMAKE_CURRENT_SOURCE_DIR}/include/OpenAlDependency
    ${CMAKE_CURRENT_SOURCE_DIR}/include/OpenGlDependency
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Physics
    ${CMAKE_CURRENT_SOURCE_DIR}/include/SpriteComponent
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Systems
    ${CMAKE_CURRENT_SOURCE_DIR}/include/UiColorElementComponent
    ${CMAKE_CURRENT_SOURCE_DIR}/include/UiElementComponent
    ${CMAKE_CURRENT_SOURCE_DIR}/include/UiLabelComponent
    ${CMAKE_CURRENT_SOURCE_DIR}/include/UiTextureElementComponent
)

set(source
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AnimeFramework/AnimeFramework.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AnimeFramework/Entity.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AnimeFramework/EventManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AnimeFramework/GameLoop.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AnimeFramework/InputManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AnimeFramework/Scene.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AnimeFramework/SceneLoader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AnimeFramework/SceneManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AudioSystem/AudioSource.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AudioSystem/AudioSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/CameraComponent/Camera.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/CameraComponent/CameraSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/FileSystem/FileSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/FileSystem/TableReader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Graphics/Renderer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Logger/Logger.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Math/Graph.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OpenAlDependency/AudioPlayWrapper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OpenGlDependency/DrawTextureWrapper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OpenGlDependency/TransposeMathWrapper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OpenGlDependency/UiContextWrapper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OpenGlDependency/Window.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Physics/Body.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Physics/BodyDefinition.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Physics/CollisionHandler.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Physics/Manifold.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Physics/PhysicsSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Physics/PhysicsWorld.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Physics/Shape.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/SpriteComponent/Sprite.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/SpriteComponent/SpriteSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Systems/SystemManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UiColorElementComponent/UiColorElement.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UiColorElementComponent/UiColorElementSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UiElementComponent/UiElement.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UiElementComponent/UiElementSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UiLabelComponent/UiLabel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UiLabelComponent/UiLabelSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UiTextureElementComponent/UiTextureElement.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UiTextureElementComponent/UiTextureElementSystem.cpp
)

if(ENABLE_COVERAGE)
    add_compile_options(-fprofile-arcs -ftest-coverage)
endif()

if(ENABLE_CLANG_TIDY AND NOT ENABLE_TESTING AND NOT ENABLE_COVERAGE)
    string(REPLACE "${PROJECT_SOURCE_DIR}" "-I${PROJECT_SOURCE_DIR}" clang_tidy_includes "${include_locations}")

    find_program(CLANG_TIDY "clang-tidy")
    add_custom_target(
        AnimeDefendersEngine_TIDY_TARGET ALL
        COMMAND clang-tidy
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
        AnimeDefendersEngine_FORMAT_CHECK_TARGET ALL
        COMMAND clang-format
        --dry-run
        --Werror
        -style=file:${PROJECT_SOURCE_DIR}/configs/.clang-format
        ${source}
        ${include_files}
    )
    add_custom_target(
        AnimeDefendersEngine_FORMAT_TARGET ALL
        COMMAND clang-format
        -i
        --Werror
        -style=file:${PROJECT_SOURCE_DIR}/configs/.clang-format
        ${source}
        ${include_files}
    )
endif()

if(ENABLE_CPPCHECK)
    find_program(CPPCHECK "cppcheck")
    add_custom_target(
        AnimeDefendersEngine_CPPCHECK_TARGET ALL
        COMMAND cppcheck
        --enable=all
        --suppress=missingInclude
        --std=c++20
        ${source}
        ${include_files}
    )
endif()

add_library(${project_name} STATIC ${source})
target_include_directories(${project_name} PUBLIC ${include_locations})

find_package(OpenGL COMPONENTS OpenGL REQUIRED)
find_package(GLUT COMPONENTS GLUT REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

target_link_libraries(${project_name} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

if(ENABLE_CLANG_FORMAT)
    add_dependencies(${project_name} AnimeDefendersEngine_FORMAT_TARGET)
endif()

if(ENABLE_CLANG_TIDY)
    add_dependencies(${project_name} AnimeDefendersEngine_TIDY_TARGET)
endif()

if(ENABLE_CPPCHECK)
    add_dependencies(${project_name} AnimeDefendersEngine_CPPCHECK_TARGET)
endif()

if(ENABLE_COVERAGE)
    target_link_libraries(${project_name} gcov)
endif()
