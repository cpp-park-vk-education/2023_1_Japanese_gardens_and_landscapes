#pragma once

#include "Body.hpp"
#include "CollisionHandler.hpp"
#include "ContactEvent.hpp"

#include <memory>
#include <unordered_set>
#include <vector>

namespace AnimeDefendersEngine::Physics {

    struct BodyDefinition;
    class Body;

}  // namespace AnimeDefendersEngine::Physics

namespace AnimeDefendersEngine::Physics {

    class PhysicsWorld {
     public:
        explicit PhysicsWorld(std::unique_ptr<CollisionHandler> collisionHandler);
        PhysicsWorld(std::unique_ptr<CollisionHandler> collisionHandler, float fixedDeltaTime, float maxDeltaTime);
        auto setFixedDeltaTime(float fixedDeltaTime) -> void;
        auto update(float deltaTime) -> void;
        [[maybe_unused]] auto fixedUpdate() -> std::vector<ContactEvent>;
        [[nodiscard]] auto addBody(BodyDefinition&& bodyDefinition) -> Body*;
        auto removeBodies() -> void;

     private:
        auto getEvents(const std::unordered_set<Contact>& currentContacts) -> std::vector<ContactEvent>;

     private:
        std::unique_ptr<CollisionHandler> m_collisionHandler;
        std::vector<std::unique_ptr<Body>> m_bodies;
        std::unordered_set<Contact> m_contacts;

        float m_fixedDeltaTime{};
        float m_maxDeltaTime{};
        float m_accumulator{};
    };

}  // namespace AnimeDefendersEngine::Physics
