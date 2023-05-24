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

    namespace {

        inline auto getIDs(const Manifold& manifold) {
            return std::tie(manifold.bodyA->getID(), manifold.bodyB->getID());
        }

        inline auto operator==(const Manifold& left, const Manifold& right) {
            return getIDs(left) == getIDs(right);
        }

    }  // namespace

}  // namespace AnimeDefendersEngine::Physics
