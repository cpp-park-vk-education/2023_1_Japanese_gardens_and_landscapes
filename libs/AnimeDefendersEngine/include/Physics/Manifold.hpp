#pragma once

#include "Body.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine::Physics {

    struct Manifold {
        Manifold(Body* bodyA, Body* bodyB);
        Manifold() = default;

        auto correctPositions() -> void;

        Body* bodyA{nullptr};
        Body* bodyB{nullptr};
        float penetration{0};
        Math::Vector2f normal;
    };

}  // namespace AnimeDefendersEngine::Physics
