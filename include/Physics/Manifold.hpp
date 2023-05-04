#pragma once

#include "Body.hpp"

namespace AnimeDefendersEngine {
    namespace PhysicsEngine {
        class Manifold {
            Body* bodyA;
            Body* bodyB;
            float penetration;
            // Vector2d normal;
        };
    }  // namespace PhysicsEngine
}  // namespace AnimeDefendersEngine