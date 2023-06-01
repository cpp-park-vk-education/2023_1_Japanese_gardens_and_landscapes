#include "Manifold.hpp"

#include <tuple>

namespace AnimeDefendersEngine::Physics {

    Manifold::Manifold(Body* bodyA, Body* bodyB) {
        if (bodyA->getID() <= bodyB->getID()) {
            this->bodyA = bodyA;
            this->bodyB = bodyB;
        } else {
            this->bodyA = bodyB;
            this->bodyB = bodyA;
        }
    }

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

}  // namespace AnimeDefendersEngine::Physics
