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
            auto hasCollision(IBody*, IBody*) -> bool;
            auto specifyCollision(Manifold) -> void;
            auto resolveCollision(Manifold) -> void;
        };
    }  // namespace PhysicsEngine
}  // namespace AnimeDefendersEngine