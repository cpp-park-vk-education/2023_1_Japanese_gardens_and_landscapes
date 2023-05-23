#pragma once

#include "Manifold.hpp"

#include <memory>
#include <string>
#include <unordered_set>
#include <vector>

namespace AnimeDefendersEngine::Physics {

    struct BodyDefinition;
    class Body;
    class CollisionHandler;

}  // namespace AnimeDefendersEngine::Physics

namespace AnimeDefendersEngine::Physics {

    enum class ContactEventType {
        ContactEnter,
        ContactStay,
        ContactExit
    };

    struct ContactEvent {
        ContactEvent(std::string bodyAID, std::string bodyBID, ContactEventType type);
        std::string bodyAID;
        std::string bodyBID;
        ContactEventType type;
    };

    constexpr float defaultFixedUpdateFrequency = 60.f;
    constexpr float defaultMinUpdateFrequency = 25.f;

    class PhysicsWorld {
     public:
        PhysicsWorld(std::unique_ptr<CollisionHandler> collisionHandler, float fixedDeltaTime = 1.f / defaultFixedUpdateFrequency,
                     float maxDeltaTime = 1.f / defaultMinUpdateFrequency);
        auto setFixedDeltaTime(float fixedDeltaTime) -> void;
        auto update(float deltaTime) -> void;
        auto fixedUpdate() -> std::vector<ContactEvent>;
        [[nodiscard]] auto addBody(BodyDefinition&& bodyDefinition) -> Body*;

     private:
        std::unique_ptr<CollisionHandler> m_collisionHandler;
        std::vector<std::unique_ptr<Body>> m_bodies;
        std::unordered_set<Manifold> m_contacts;

        float m_fixedDeltaTime;
        float m_maxDeltaTime;
        float m_accumulator{0};
    };

}  // namespace AnimeDefendersEngine::Physics
