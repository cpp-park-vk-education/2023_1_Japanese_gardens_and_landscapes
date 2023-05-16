#include "CollisionHandler.hpp"

using namespace AnimeDefendersEngine::PhysicsEngine;

auto CollisionHandler::broadPhase(const std::vector<IBody*>&) -> std::vector<Manifold> {
    return {};
}

auto CollisionHandler::narrowPhase(std::vector<Manifold>&) -> void {}

auto CollisionHandler::hasCollision(IBody*, IBody*) -> bool {
    return false;
}

auto CollisionHandler::specifyCollision(Manifold) -> void {}

auto CollisionHandler::resolveCollision(Manifold) -> void {}
