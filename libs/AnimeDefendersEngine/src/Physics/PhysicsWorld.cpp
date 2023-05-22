#include "PhysicsWorld.hpp"
#include <memory>
#include "Body.hpp"
#include "BodyDefinition.hpp"
#include "CollisionHandler.hpp"
#include "Manifold.hpp"

using namespace AnimeDefendersEngine::Physics;

PhysicsWorld::PhysicsWorld(std::unique_ptr<CollisionHandler> collisionHandler, float fixedDeltaTime, float maxDeltaTime)
    : m_collisionHandler(std::move(collisionHandler)), m_fixedDeltaTime(fixedDeltaTime), m_maxDeltaTime(maxDeltaTime) {}

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

auto PhysicsWorld::fixedUpdate() -> void {
    std::vector<Body*> bodies;
    bodies.reserve((m_bodies.size()));
    for (const auto& body : m_bodies) {
        if (body->getType() == BodyType::dynamicBody) {
            body->integrateForce(m_fixedDeltaTime);
            body->integrateVelocity(m_fixedDeltaTime);
        }
        bodies.push_back(body.get());
    }

    std::vector<Manifold> currentContacts = m_collisionHandler->broadPhase(bodies);
    m_collisionHandler->narrowPhase(currentContacts);

    for (const auto& body : m_bodies) {
        body->clearForce();
        body->clearVelocity();
    }
    std::swap(m_contacts, currentContacts);
}
