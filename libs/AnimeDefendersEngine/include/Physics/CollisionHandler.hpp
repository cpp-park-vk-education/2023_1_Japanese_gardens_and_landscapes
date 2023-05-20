#pragma once

#include "ICollisionHandler.hpp"

#include <vector>

namespace AnimeDefendersEngine::Physics {

    class ICollisionHandler;
    class Body;
    struct Manifold;

}  // namespace AnimeDefendersEngine::Physics

namespace AnimeDefendersEngine::Physics {

    class CollisionHandler : public ICollisionHandler {
     public:
        [[nodiscard]] virtual auto broadPhase(const std::vector<Body*>& bodies) const -> std::vector<Manifold> override final;
        virtual auto narrowPhase(std::vector<Manifold>& bodies) const -> void override final;
        virtual auto hasCollision(Body* bodyA, Body* bodyB) const -> bool override final;
        virtual auto specifyCollision(Manifold& contact) const -> void override final;
        virtual auto resolveCollision(Manifold& contact) const -> void override final;
    };

}  // namespace AnimeDefendersEngine::Physics
