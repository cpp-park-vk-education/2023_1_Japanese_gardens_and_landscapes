#include "PhysicsWorld.hpp"

using namespace AnimeDefendersEngine::PhysicsEngine;

PhysicsWorld::PhysicsWorld(const float fixedDeltaTime){};
auto PhysicsWorld::setFixedDeltaTime(const float fixedDeltaTime) -> void{};
auto PhysicsWorld::update(const float timeStep) -> void{};
auto PhysicsWorld::addBody(const BodyDefinition& bodyDefinition) -> IBody* {};
auto PhysicsWorld::removeBody(IBody* body) -> void{};
auto PhysicsWorld::fixedUpdate() -> void{};
