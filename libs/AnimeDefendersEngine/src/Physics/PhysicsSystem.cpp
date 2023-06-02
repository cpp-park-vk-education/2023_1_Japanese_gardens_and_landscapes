#include "PhysicsSystem.hpp"
#include "Body.hpp"
#include "ColliderComponent.hpp"
#include "CollisionHandler.hpp"
#include "Component.hpp"
#include "Scene.hpp"
#include "TransformComponent.hpp"

#include <memory>

namespace AnimeDefendersEngine::Physics {

    namespace {

        constexpr float defaultFixedUpdateFrequency = 60.f;
        constexpr float defaultMinUpdateFrequency = 25.f;

    }  // namespace

    PhysicsSystem::PhysicsSystem(float fixedDeltaTime, float maxDeltaTime)
        : m_physicsWorld(std::make_unique<CollisionHandler>(), fixedDeltaTime, maxDeltaTime) {}

    PhysicsSystem::PhysicsSystem() : PhysicsSystem(1.f / defaultFixedUpdateFrequency, 1.f / defaultMinUpdateFrequency) {}

    auto PhysicsSystem::setFixedDeltaTime(float fixedDeltaTime) noexcept -> void {
        m_physicsWorld.setFixedDeltaTime(fixedDeltaTime);
    }

    auto PhysicsSystem::updateSystem(SceneManager& sceneManager, float fixedDeltaTime) -> void {
        ComponentManager& componentManager = sceneManager.getActiveScene().getComponentManager();
        auto components = componentManager.getComponents<ColliderComponent>();

        std::vector<Body*> bodies = addBodies(components);

        // std::cout << bodies.size() << std::endl;
        m_physicsWorld.setFixedDeltaTime(fixedDeltaTime);
        m_contactEvents = m_physicsWorld.fixedUpdate();

        for (const auto& body : bodies) {
            auto* collider = static_cast<ColliderComponent*>(components.at(body->getID()));
            collider->getTransform().position = body->getPosition();
        }

        return;

        processContactEvents(components);

        m_physicsWorld.removeBodies();
    }

    auto PhysicsSystem::addBodies(ComponentManager::ComponentsContainer& components) -> std::vector<Body*> {
        std::vector<Body*> bodies{};
        bodies.reserve(components.size());
        for (const auto& component : components) {
            auto* collider = static_cast<ColliderComponent*>(component.second);
            BodyDefinition bodyDef{};
            bodyDef.id = collider->getEntityId();
            switch (collider->getShapeType()) {
                case ShapeType::rectangle:
                    bodyDef.shape = std::make_unique<Rectangle>(collider->getSize());
                    break;

                case ShapeType::circle:
                    bodyDef.shape = std::make_unique<Circle>(collider->getRadius());
                    break;
            }
            bodyDef.transform.position = collider->getTransform().position;

            bodyDef.isTrigger = collider->isTrigger();

            if (collider->getRigidBody() != nullptr) {
                bodyDef.mass = collider->getRigidBody()->mass;
                bodyDef.bodyType = BodyType::dynamicBody;
            } else {
                bodyDef.bodyType = BodyType::staticBody;
            }
            auto* body = m_physicsWorld.addBody(std::move(bodyDef));

            if (collider->getRigidBody() != nullptr) {
                body->applyImpulse(collider->getRigidBody()->velocity);
            }

            bodies.push_back(body);
        }
        return bodies;
    }

    auto PhysicsSystem::processContactEvents(ComponentManager::ComponentsContainer& colliders) -> void {
        for (auto event : m_contactEvents) {
            auto* bodyA = static_cast<ColliderComponent*>(colliders.at(event.contact.bodyAID));
            auto* bodyB = static_cast<ColliderComponent*>(colliders.at(event.contact.bodyBID));

            switch (event.type) {
                case ContactEventType::ContactEnter:
                    bodyA->onCollisionEnter(*bodyB);
                    bodyB->onCollisionEnter(*bodyA);
                    break;

                case ContactEventType::ContactStay:
                    bodyA->onCollisionStay(*bodyB);
                    bodyB->onCollisionStay(*bodyA);
                    break;

                case ContactEventType::ContactExit:
                    bodyA->onCollisionExit(*bodyB);
                    bodyB->onCollisionExit(*bodyA);
                    break;
            }
        }
    }

}  // namespace AnimeDefendersEngine::Physics
