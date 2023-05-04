#include "PhysicsSystem.hpp"

using namespace AnimeDefendersEngine;

PhysicsSystem(float fixedDeltaTime){};
virtual auto updateSystem(ComponentManager& componentManager) -> void override{};
auto updateSystem(ComponentManager& componentManager, float timeStep) -> void{};
auto setFixedDeltaTime(float fixedDeltaTime) -> void{};