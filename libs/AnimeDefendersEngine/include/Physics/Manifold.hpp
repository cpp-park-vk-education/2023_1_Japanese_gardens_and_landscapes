#pragma once

#include "Body.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine {
    namespace Physics {

        struct Manifold {
            Body* bodyA{nullptr};
            Body* bodyB{nullptr};
            float penetration{};
            Math::Vector2<float> normal{};
            explicit Manifold(Body* bodyA, Body* bodyB);
            Manifold(){};
        };

    }  // namespace Physics
}  // namespace AnimeDefendersEngine
