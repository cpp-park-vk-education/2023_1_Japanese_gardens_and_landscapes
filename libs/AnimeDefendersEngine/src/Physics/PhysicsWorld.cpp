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

    auto PhysicsWorld::update(float deltaTime) -> void {
        m_accumulator += deltaTime;
        if (m_accumulator > m_maxDeltaTime) {
            m_accumulator = m_maxDeltaTime;
        }
        while (m_accumulator >= m_fixedDeltaTime) {
            fixedUpdate();
            m_accumulator -= m_fixedDeltaTime;
        }
    }

    auto PhysicsWorld::addBody(BodyDefinition&& bodyDefinition) -> Body* {
        m_bodies.push_back(std::make_unique<Body>(std::move(bodyDefinition)));
        return m_bodies.back().get();
    }

    auto PhysicsWorld::getEvents(std::unordered_set<Manifold> currentContacts) -> std::vector<ContactEvent> {
        std::vector<ContactEvent> events;
        events.reserve(currentContacts.size());
        for (auto currentContact : currentContacts) {
            if (m_contacts.contains(currentContact)) {
                events.emplace_back(currentContact.bodyA->getID(), currentContact.bodyB->getID(), ContactEventType::ContactStay);
                m_contacts.erase(currentContact);
            } else {
                events.emplace_back(currentContact.bodyA->getID(), currentContact.bodyB->getID(), ContactEventType::ContactEnter);
            }
        }

        for (auto leftContact : m_contacts) {
            events.emplace_back(leftContact.bodyA->getID(), leftContact.bodyB->getID(), ContactEventType::ContactExit);
        }
        return events;
    }

    auto PhysicsWorld::fixedUpdate() -> std::vector<ContactEvent> {
        std::vector<Body*> bodies;
        bodies.reserve((m_bodies.size()));
        for (const auto& body : m_bodies) {
            if (body->getType() == BodyType::dynamicBody) {
                body->integrateForce(m_fixedDeltaTime);
                body->integrateVelocity(m_fixedDeltaTime);
            }
            bodies.push_back(body.get());
        }

        std::unordered_set<Manifold> currentContacts = m_collisionHandler->broadPhase(bodies);
        m_collisionHandler->narrowPhase(currentContacts);

        for (const auto& body : m_bodies) {
            body->clearForce();
            body->clearVelocity();
        }

        std::vector<ContactEvent> events = getEvents(currentContacts);

        std::swap(m_contacts, currentContacts);

        return events;
    }

}  // namespace AnimeDefendersEngine::Physics
