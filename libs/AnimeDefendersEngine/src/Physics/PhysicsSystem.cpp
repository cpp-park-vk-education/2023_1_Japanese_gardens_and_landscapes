#include "PhysicsSystem.hpp"
#include "Body.hpp"
#include "BodyDefinition.hpp"
#include "Component.hpp"
#include "ComponentManager.hpp"

#include <memory>

using namespace AnimeDefendersEngine::Physics;

auto PhysicsSystem::updateSystem(SceneManager& sceneManager, float fixedDeltaTime) -> void {
    using AnimeDefendersEngine::Math::Vector2f;

    // Нужно сделать компоненты

        // ComponentManager& componentManager = sceneManager.getActiveScene().getComponentManager();
    // auto colliders = componentManager.getComponents<Collider2DComponent>();

    // std::vector<Body*> bodies;
    // bodies.reserve(colliders.size());
    // for (auto collider : colliders) {
    //     BodyDefinition bodyDef;
    //     bodyDef.id = collider.getEntityID();
    //     bodyDef.shape = std::make_unique<Rectangle>(collider.size);
    //     bodyDef.transform.position = collider.transformComponent.position;

    //     Body* body = m_physicsWorld.addBody(std::move(bodyDef));

    //     if (collider.rigidBody2DComponent == nullptr) {
    //         body->setType(BodyType::staticBody);
    //     } else {
    //         body->setType(BodyType::dynamicBody);
    //         body->applyImpulse(collider.rigidBody2DComponent.velocity);
    //     }

    //     bodies.push_back(body);
    // }

    // m_physicsWorld.setFixedDeltaTime(fixedDeltaTime);
    // m_physicsWorld.fixedUpdate();

    // for (auto body : bodies) {
    //     colliders.at(body->getID()).transformComponent.position = body->getPosition();
    // }
}

auto PhysicsSystem::setFixedDeltaTime(float fixedDeltaTime) noexcept -> void {
    m_physicsWorld.setFixedDeltaTime(fixedDeltaTime);
}
