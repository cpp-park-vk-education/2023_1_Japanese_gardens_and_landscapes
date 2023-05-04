#pragma once

#include "Body.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine {
    namespace PhysicsEngine {
        class Manifold {
            Body* bodyA;
            Body* bodyB;
            float penetration;
            Math::Vector2<float> normal;
        };
    }  // namespace PhysicsEngine
}  // namespace AnimeDefendersEngine