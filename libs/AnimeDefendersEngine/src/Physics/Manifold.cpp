#include "Manifold.hpp"

namespace AnimeDefendersEngine::Physics {

    Manifold::Manifold(Body* bodyA, Body* bodyB) : bodyA(bodyA), bodyB(bodyB) {}

    namespace {

        constexpr float correctionPercent = 0.5f;
        constexpr float tolerance = 0.05f;

    }  // namespace

    auto Manifold::correctPositions() -> void {
        const auto correction =
            correctionPercent * std::max(penetration - tolerance, 0.f) / (bodyA->getInverseMass() + bodyB->getInverseMass()) * normal;
        bodyA->setPosition(bodyA->getPosition() - correctionPercent * bodyA->getInverseMass() * correction);
        bodyB->setPosition(bodyB->getPosition() + correctionPercent * bodyB->getInverseMass() * correction);
    }

    auto operator==(const Manifold& left, const Manifold& right) -> bool {
        return left.bodyA->getID() == right.bodyA->getID() && left.bodyB->getID() == right.bodyB->getID() ||
               left.bodyA->getID() == right.bodyB->getID() && left.bodyB->getID() == right.bodyA->getID();
    }

}  // namespace AnimeDefendersEngine::Physics
