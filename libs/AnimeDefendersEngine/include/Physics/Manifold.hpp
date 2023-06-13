#pragma once

#include "Body.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine {
    namespace Physics {
        struct Manifold {
            IBody* bodyA;
            IBody* bodyB;
            float penetration;
            Math::Vector2<float> normal;
            explicit Manifold(IBody* bodyA = nullptr, IBody* bodyB = nullptr);
        };
    }  // namespace Physics
}  // namespace AnimeDefendersEngine
