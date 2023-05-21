#include "PhysicsSystem.hpp"
#include "Body.hpp"
#include "BodyDefinition.hpp"
#include "Collider2DComponent.hpp"
#include "Component.hpp"
#include "ComponentManager.hpp"
#include "SceneManager.hpp"

#include <memory>

using namespace AnimeDefendersEngine;

auto Physics::PhysicsSystem::updateSystem(SceneManager& sceneManager, float fixedDeltaTime) -> void {
    using AnimeDefendersEngine::Math::Vector2f;

    ComponentManager& componentManager = sceneManager.getActiveScene().getComponentManager();
    auto colliders = componentManager.getComponents<Collider2DComponent>();

    std::vector<Physics::Body*> bodies;
    bodies.reserve(colliders.size());
    for (auto collider : colliders) {
        Physics::BodyDefinition bodyDef;
        bodyDef.id = collider.second->getEntityId();
        bodyDef.shape = std::make_unique<Physics::Rectangle>(collider.second->size);
        bodyDef.transform.position = collider.second->transformComponent.position;

        Physics::Body* body = m_physicsWorld.addBody(std::move(bodyDef));

        if (collider.second->rigidBody2DComponent == nullptr) {
            body->setType(Physics::BodyType::staticBody);
        } else {
            body->setType(Physics::BodyType::dynamicBody);
            body->applyImpulse(collider.second->rigidBody2DComponent.velocity);
        }

        bodies.push_back(body);
    }

    m_physicsWorld.setFixedDeltaTime(fixedDeltaTime);
    m_physicsWorld.fixedUpdate();

    for (auto body : bodies) {
        colliders.at(body->getID()).transformComponent.position = body->getPosition();
    }
}

auto Physics::PhysicsSystem::setFixedDeltaTime(float fixedDeltaTime) noexcept -> void {
    m_physicsWorld.setFixedDeltaTime(fixedDeltaTime);
}
