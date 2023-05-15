#include "PhysicsWorld.hpp"

using namespace AnimeDefendersEngine::PhysicsEngine;

PhysicsWorld::PhysicsWorld(const float) {}

auto PhysicsWorld::setFixedDeltaTime(const float) -> void {}

auto PhysicsWorld::update(const float) -> void {}

auto PhysicsWorld::addBody(const BodyDefinition&) -> IBody* {
    return nullptr;
}

auto PhysicsWorld::removeBody(IBody*) -> void {}

auto PhysicsWorld::fixedUpdate() -> void {}
