#include "Manifold.hpp"

#include <tuple>

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
        const auto leftIDs = std::make_tuple(left.bodyA->getID(), left.bodyB->getID());
        const auto rightIDs = std::make_tuple(right.bodyA->getID(), right.bodyB->getID());
        const auto reverseRightIDs = std::make_tuple(right.bodyB->getID(), right.bodyA->getID());
        return std::tie(leftIDs) == std::tie(rightIDs) || std::tie(leftIDs) == std::tie(reverseRightIDs);
    }

}  // namespace AnimeDefendersEngine::Physics
