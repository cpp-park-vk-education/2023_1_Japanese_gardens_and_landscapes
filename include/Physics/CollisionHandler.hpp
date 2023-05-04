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
            virtual auto hasCollision(IBody* bodyA, IBody* bodyB) -> bool = 0;
            virtual auto specifyCollision(Manifold contact) -> void = 0;
            virtual auto resolveCollision(Manifold contact) -> void = 0;
        };

        class CollisionHandler : public ICollisionHandler {};
    }  // namespace PhysicsEngine
}  // namespace AnimeDefendersEngine