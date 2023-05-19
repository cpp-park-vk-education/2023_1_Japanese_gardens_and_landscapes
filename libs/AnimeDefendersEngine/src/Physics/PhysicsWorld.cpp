#include "PhysicsWorld.hpp"
#include "Body.hpp"
#include "BodyDefinition.hpp"
#include "CollisionHandler.hpp"
#include "Manifold.hpp"

#include <iostream>
#include <memory>

using namespace AnimeDefendersEngine::Physics;

PhysicsWorld::PhysicsWorld(std::unique_ptr<CollisionHandler>&& collisionHandler, float fixedDeltaTime, float maxDeltaTime)
    : m_collisionHandler(std::move(collisionHandler)), m_fixedDeltaTime(fixedDeltaTime), m_maxDeltaTime(maxDeltaTime), m_accumulator(0) {}

auto PhysicsWorld::setFixedDeltaTime(float fixedDeltaTime) -> void {}

auto PhysicsWorld::update(float deltaTime) -> void {}

auto PhysicsWorld::addBody(BodyDefinition&& bodyDefinition) -> Body* {}

auto PhysicsWorld::fixedUpdate() -> void {}
