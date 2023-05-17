#include "PhysicsWorld.hpp"

using namespace AnimeDefendersEngine::Physics;

PhysicsWorld::PhysicsWorld(const float) {}

auto PhysicsWorld::setFixedDeltaTime(const float) -> void {}

auto PhysicsWorld::update(const float) -> void {}

auto PhysicsWorld::addBody(const BodyDefinition&) -> Body* {
    return nullptr;
}

auto PhysicsWorld::removeBody(Body*) -> void {}

auto PhysicsWorld::fixedUpdate() -> void {}
