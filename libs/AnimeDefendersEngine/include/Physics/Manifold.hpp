#pragma once

#include "Body.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine {
    namespace Physics {

        class Manifold {
            Body* bodyA;
            Body* bodyB;
            float penetration;
            Math::Vector2<float> normal;
        };

    }  // namespace Physics
}  // namespace AnimeDefendersEngine
