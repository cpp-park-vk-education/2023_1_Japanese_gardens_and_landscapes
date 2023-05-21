#pragma once

#include <memory>
#include <vector>

namespace AnimeDefendersEngine::Physics {

    struct BodyDefinition;
    class Body;
    struct Manifold;
    class CollisionHandler;

}  // namespace AnimeDefendersEngine::Physics

namespace AnimeDefendersEngine::Physics {

    class PhysicsWorld {
     public:
        PhysicsWorld(std::unique_ptr<CollisionHandler>&& collisionHandler, float fixedDeltaTime, float maxDeltaTime);
        auto setFixedDeltaTime(float fixedDeltaTime) -> void;
        auto update(float deltaTime) -> void;
        [[nodiscard]] auto addBody(BodyDefinition&& bodyDefinition) -> Body*;

     private:
        auto fixedUpdate() -> void;

        std::unique_ptr<CollisionHandler> m_collisionHandler;
        std::vector<std::unique_ptr<Body>> m_bodies;
        std::vector<Manifold> m_contacts;

        float m_fixedDeltaTime{};
        float m_maxDeltaTime{};
        float m_accumulator{};
    };

}  // namespace AnimeDefendersEngine::Physics
