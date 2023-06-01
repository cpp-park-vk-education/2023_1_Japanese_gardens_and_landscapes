#pragma once

#include "ICollisionHandler.hpp"

namespace AnimeDefendersEngine::Physics {

    class CollisionHandler final : public ICollisionHandler {
     public:
        [[nodiscard]] auto broadPhase(const std::vector<Body*>& bodies) const -> std::vector<Manifold> override;
        [[maybe_unused]] auto narrowPhase(std::vector<Manifold>& manifolds) const -> std::unordered_set<Contact> override;
        [[nodiscard]] auto hasCollision(Body* bodyA, Body* bodyB) const -> bool override;
        auto specifyCollision(Manifold& manifold) const -> void override;
        auto resolveCollision(Manifold& manifold) const -> void override;
    };

}  // namespace AnimeDefendersEngine::Physics
