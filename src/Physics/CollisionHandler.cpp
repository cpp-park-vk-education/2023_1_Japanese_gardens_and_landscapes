#include "CollisionHandler.hpp"

using namespace AnimeDefendersEngine::PhysicsEngine;

auto CollisionHandler::broadPhase(const std::vector<IBody*>& bodies) -> std::vector<Manifold>{};
auto CollisionHandler::narrowPhase(std::vector<Manifold>& bodies) -> void{};

auto CollisionHandler::hasCollision(IBody* bodyA, IBody* bodyB) -> bool{};
auto CollisionHandler::specifyCollision(Manifold contact) -> void{};
auto CollisionHandler::resolveCollision(Manifold contact) -> void{};