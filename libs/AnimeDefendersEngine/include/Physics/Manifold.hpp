#pragma once

#include "Body.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine::Physics {

    struct Manifold {
        Body* bodyA;
        Body* bodyB;
        float penetration{};
        Math::Vector2<float> normal;
        explicit Manifold(Body* bodyA, Body* bodyB);
        Manifold() = default;
    };

}  // namespace AnimeDefendersEngine::Physics
