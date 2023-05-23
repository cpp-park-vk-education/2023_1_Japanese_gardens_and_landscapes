#pragma once

#include "ICollisionHandler.hpp"

#include <unordered_set>
#include <vector>

namespace AnimeDefendersEngine::Physics {

    class Body;
    struct Manifold;

}  // namespace AnimeDefendersEngine::Physics

namespace AnimeDefendersEngine::Physics {

    class CollisionHandler final : public ICollisionHandler {
     public:
        [[nodiscard]] virtual auto broadPhase(const std::vector<Body*>& bodies) const -> std::unordered_set<Manifold> override;
        virtual auto narrowPhase(std::unordered_set<Manifold>& bodies) const -> void override;
        [[nodiscard]] virtual auto hasCollision(Body* bodyA, Body* bodyB) const -> bool override;
        virtual auto specifyCollision(Manifold& contact) const -> void override;
        virtual auto resolveCollision(Manifold& contact) const -> void override;
    };

}  // namespace AnimeDefendersEngine::Physics
