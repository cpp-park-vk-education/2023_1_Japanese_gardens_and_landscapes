#include "Manifold.hpp"

using namespace AnimeDefendersEngine::Physics;

Manifold::Manifold(Body* bodyA, Body* bodyB) : bodyA(bodyA), bodyB(bodyB) {}

constexpr float correctionPercent = 0.5f;
constexpr float tolerance = 0.05f;

auto Manifold::correctPositions() -> void {
    const auto correction =
        correctionPercent * std::max(penetration - tolerance, 0.0f) / (bodyA->getInverseMass() + bodyB->getInverseMass()) * normal;
    bodyA->setPosition(bodyA->getPosition() - correctionPercent * bodyA->getInverseMass() * correction);
    bodyB->setPosition(bodyB->getPosition() + correctionPercent * bodyB->getInverseMass() * correction);
}
