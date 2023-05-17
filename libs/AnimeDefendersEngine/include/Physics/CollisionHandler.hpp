#pragma once

#include <vector>

#include "Body.hpp"
#include "Manifold.hpp"

namespace AnimeDefendersEngine {
    namespace Physics {

        class ICollisionHandler {
         public:
            virtual auto broadPhase(const std::vector<Body*>& bodies) -> std::vector<Manifold> = 0;
            virtual auto narrowPhase(std::vector<Manifold>& contacts) -> void = 0;
            virtual auto hasCollision(Body* bodyA, Body* bodyB) -> bool = 0;
            virtual auto specifyCollision(Manifold& contact) -> void = 0;
            virtual auto resolveCollision(Manifold& contact) -> void = 0;
        };

        class CollisionHandler : public ICollisionHandler {
         public:
            virtual auto broadPhase(const std::vector<Body*>& bodies) -> std::vector<Manifold> override;
            virtual auto narrowPhase(std::vector<Manifold>& bodies) -> void override;
            virtual auto hasCollision(Body* bodyA, Body* bodyB) -> bool override;
            virtual auto specifyCollision(Manifold& contact) -> void override;
            virtual auto resolveCollision(Manifold& contact) -> void override;
        };

    }  // namespace Physics
}  // namespace AnimeDefendersEngine
