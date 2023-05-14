#include "PhysicsSystem.hpp"

using namespace AnimeDefendersEngine::PhysicsEngine;

PhysicsSystem::PhysicsSystem(float fixedDeltaTime) : physicsWorld(fixedDeltaTime) {}

auto PhysicsSystem::updateSystem(ComponentManager& componentManager) -> void {}

auto PhysicsSystem::updateSystem(ComponentManager& componentManager, float timeStep) -> void {}

auto PhysicsSystem::setFixedDeltaTime(float fixedDeltaTime) -> void {}
