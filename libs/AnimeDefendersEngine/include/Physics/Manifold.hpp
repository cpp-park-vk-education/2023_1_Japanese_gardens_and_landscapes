#pragma once

#include "Body.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine::Physics {

    struct Manifold {
        explicit Manifold(Body* bodyA, Body* bodyB);
        Manifold() = default;

        auto correctPositions() -> void;
        Body* bodyA;
        Body* bodyB;
        float penetration{0};
        Math::Vector2f normal;
    };

}  // namespace AnimeDefendersEngine::Physics
