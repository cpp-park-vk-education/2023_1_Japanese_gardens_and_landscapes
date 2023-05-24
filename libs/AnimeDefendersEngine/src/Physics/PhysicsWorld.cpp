#include "PhysicsWorld.hpp"
#include "Body.hpp"
#include "BodyDefinition.hpp"
#include "CollisionHandler.hpp"
#include "ContactEvent.hpp"
#include "Manifold.hpp"

#include <memory>
#include <unordered_set>

namespace AnimeDefendersEngine::Physics {

    namespace {

        constexpr float defaultFixedUpdateFrequency = 60.f;
        constexpr float defaultMinUpdateFrequency = 25.f;

    }  // namespace

    PhysicsWorld::PhysicsWorld(std::unique_ptr<CollisionHandler> collisionHandler, float fixedDeltaTime, float maxDeltaTime)
        : m_collisionHandler(std::move(collisionHandler)), m_fixedDeltaTime(fixedDeltaTime), m_maxDeltaTime(maxDeltaTime) {}

    PhysicsWorld::PhysicsWorld(std::unique_ptr<CollisionHandler> collisionHandler)
        : PhysicsWorld(std::move(collisionHandler), 1.f / defaultFixedUpdateFrequency, 1.f / defaultMinUpdateFrequency) {}

    auto PhysicsWorld::setFixedDeltaTime(float fixedDeltaTime) -> void {
        m_fixedDeltaTime = fixedDeltaTime;
    }

    auto PhysicsWorld::update(float deltaTime) -> void {}

    auto PhysicsWorld::addBody(BodyDefinition&& bodyDefinition) -> Body* {}

    auto PhysicsWorld::getEvents(std::unordered_set<Manifold> currentContacts) -> std::vector<ContactEvent> {}

    auto PhysicsWorld::fixedUpdate() -> std::vector<ContactEvent> {}

}  // namespace AnimeDefendersEngine::Physics
