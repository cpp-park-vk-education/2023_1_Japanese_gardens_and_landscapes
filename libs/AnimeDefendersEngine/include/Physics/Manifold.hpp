#pragma once

#include "Body.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine::Physics {

    struct Manifold {
        Manifold(Body* bodyA, Body* bodyB);
        Manifold() = default;

        friend auto operator==(const Manifold& left, const Manifold& right) -> bool;
        auto correctPositions() -> void;

        Body* bodyA{nullptr};
        Body* bodyB{nullptr};
        float penetration{0};
        Math::Vector2f normal;
    };

}  // namespace AnimeDefendersEngine::Physics

namespace std {

    template <>
    struct hash<AnimeDefendersEngine::Physics::Manifold> {
        size_t operator()(const AnimeDefendersEngine::Physics::Manifold& manifold) const {
            return hash<string>()(manifold.bodyA->getID()) ^ hash<string>()(manifold.bodyB->getID());
        }
    };

}  // namespace std
