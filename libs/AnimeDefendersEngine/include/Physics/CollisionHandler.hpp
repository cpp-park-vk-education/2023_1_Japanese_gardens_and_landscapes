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
        [[nodiscard]] auto broadPhase(const std::vector<Body*>& bodies) const -> std::unordered_set<Manifold> override;
        auto narrowPhase(std::unordered_set<Manifold>& contacts) const -> void override;
        [[nodiscard]] auto hasCollision(Body* bodyA, Body* bodyB) const -> bool override;
        auto specifyCollision(Manifold& contact) const -> void override;
        auto resolveCollision(Manifold& contact) const -> void override;
    };

}  // namespace AnimeDefendersEngine::Physics
