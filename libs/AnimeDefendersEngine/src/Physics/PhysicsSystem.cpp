#include "PhysicsSystem.hpp"
#include "Body.hpp"
#include "BodyDefinition.hpp"
#include "ColliderComponent.hpp"
#include "CollisionHandler.hpp"
#include "Component.hpp"
#include "ComponentManager.hpp"
#include "ContactEvent.hpp"
#include "Scene.hpp"
#include "SceneManager.hpp"

#include <memory>

namespace AnimeDefendersEngine::Physics {

    PhysicsSystem::PhysicsSystem(float fixedDeltaTime) : m_physicsWorld(std::make_unique<CollisionHandler>()) {
        m_physicsWorld.setFixedDeltaTime(fixedDeltaTime);
    }

    auto PhysicsSystem::addBodies(ComponentManager::ComponentsContainer& components) -> std::vector<Body*> {
        std::vector<Body*> bodies;
        bodies.reserve(components.size());
        for (auto component : components) {
            auto collider = static_cast<ColliderComponent*>(component.second);
            BodyDefinition bodyDef;
            bodyDef.id = collider->getEntityId();
            if (collider->shapeType == ShapeType::rectangle) {
                bodyDef.shape = std::make_unique<Rectangle>(collider->size);
            } else {
                bodyDef.shape = std::make_unique<Circle>(collider->radius);
            }
            bodyDef.transform.position = collider->transformComponent.position;

            Body* body = m_physicsWorld.addBody(std::move(bodyDef));

            if (collider->rigidBodyComponent == nullptr) {
                body->setType(BodyType::staticBody);
            } else {
                body->setType(BodyType::dynamicBody);
                body->applyImpulse(collider->rigidBodyComponent->velocity);
            }

            bodies.push_back(body);
        }
        return bodies;
    }

    auto PhysicsSystem::processContactEvents(ComponentManager::ComponentsContainer& colliders) -> void {
        for (auto event : m_contactEvents) {
            auto bodyA = static_cast<CircleColliderComponent*>(colliders.at(event.bodyAID));
            auto bodyB = static_cast<CircleColliderComponent*>(colliders.at(event.bodyBID));

            switch (event.type) {
                case ContactEventType::ContactEnter:

                    break;

                case ContactEventType::ContactStay:

                    break;

                case ContactEventType::ContactExit:

                    break;
            }
        }
    }

    auto PhysicsSystem::updateSystem(SceneManager& sceneManager, float fixedDeltaTime) -> void {
        ComponentManager& componentManager = sceneManager.getActiveScene().getComponentManager();
        auto components = componentManager.getComponents<ColliderComponent>();

        std::vector<Body*> bodies = addBodies(components);

        m_physicsWorld.setFixedDeltaTime(fixedDeltaTime);
        m_contactEvents = m_physicsWorld.fixedUpdate();

        for (const auto& body : bodies) {
            static_cast<ColliderComponent*>(components.at(body->getID()))->transformComponent.position = body->getPosition();
        }

        processContactEvents(components);
    }

    auto PhysicsSystem::setFixedDeltaTime(float fixedDeltaTime) noexcept -> void {
        m_physicsWorld.setFixedDeltaTime(fixedDeltaTime);
    }

}  // namespace AnimeDefendersEngine::Physics
