#pragma once

#include <vector>

#include "Body.hpp"
#include "Manifold.hpp"

namespace AnimeDefendersEngine {
    namespace PhysicsEngine {
        class ICollisionHandler {
         public:
            virtual auto broadPhase(const std::vector<IBody*>& bodies) -> std::vector<Manifold> = 0;
            virtual auto narrowPhase(std::vector<Manifold>& bodies) -> void = 0;

         protected:
            auto hasCollision(IBody* bodyA, IBody* bodyB) -> bool;
            auto specifyCollision(Manifold contact) -> void;
            auto resolveCollision(Manifold contact) -> void;
        };
    }  // namespace PhysicsEngine
}  // namespace AnimeDefendersEngine