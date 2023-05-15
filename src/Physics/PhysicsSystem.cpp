#include "PhysicsSystem.hpp"

using namespace AnimeDefendersEngine::PhysicsEngine;

PhysicsSystem::PhysicsSystem(float fixedDeltaTime) : physicsWorld(fixedDeltaTime) {}

auto PhysicsSystem::updateSystem(ComponentManager&) -> void {}

auto PhysicsSystem::updateSystem(ComponentManager&, float) -> void {}

auto PhysicsSystem::setFixedDeltaTime(float) -> void {}
