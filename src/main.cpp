#include <iostream>
#include "ComponentManager.hpp"
#include "PhysicsSystem.hpp"
#include "SceneManager.hpp"
#include "Vector2.hpp"

auto subMain() -> int {
    using namespace AnimeDefendersEngine;
    // SceneManager sceneManager;
    // ComponentManager compManager(0);
    Physics::PhysicsSystem system(0.1f);
    std::cout << "fdffdf";
    return 0;
}

auto main() -> int {
    return subMain();
}
