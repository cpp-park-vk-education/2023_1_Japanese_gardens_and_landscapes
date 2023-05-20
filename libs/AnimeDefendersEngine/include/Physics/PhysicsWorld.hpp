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

    constexpr float defaultFixedUpdateFrequency = 60.0f;
    constexpr float defaultMinUpdateFrequency = 25.0f;

    class PhysicsWorld {
     public:
        explicit PhysicsWorld(std::unique_ptr<CollisionHandler>&& collisionHandler,
                              float fixedDeltaTime = 1.0f / defaultFixedUpdateFrequency,
                              float maxDeltaTime = 1.0f / defaultMinUpdateFrequency);
        auto setFixedDeltaTime(float fixedDeltaTime) -> void;
        auto update(float deltaTime) -> void;
        auto fixedUpdate() -> void;
        [[nodiscard]] auto addBody(BodyDefinition&& bodyDefinition) -> Body*;

     private:
        std::unique_ptr<CollisionHandler> m_collisionHandler;
        std::vector<std::unique_ptr<Body>> m_bodies;
        std::vector<Manifold> m_contacts;

        float m_fixedDeltaTime;
        float m_maxDeltaTime;
        float m_accumulator{0};
    };

}  // namespace AnimeDefendersEngine::Physics