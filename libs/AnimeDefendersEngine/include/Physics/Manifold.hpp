#pragma once

#include "Body.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine::Physics {

    struct Manifold {
        Body* bodyA;
        Body* bodyB;
        float penetration{0};
        Math::Vector2f normal;
        explicit Manifold(Body* bodyA, Body* bodyB);
        Manifold() = default;
    };

}  // namespace AnimeDefendersEngine::Physics
