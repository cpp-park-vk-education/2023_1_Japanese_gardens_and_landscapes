#include "PhysicsSystem.hpp"
#include "Body.hpp"
#include "BodyDefinition.hpp"
#include "ColliderComponent.hpp"
#include "Component.hpp"
#include "ComponentManager.hpp"
#include "ContactEvent.hpp"
#include "Scene.hpp"
#include "SceneManager.hpp"

#include <memory>

namespace AnimeDefendersEngine {

    Physics::PhysicsSystem::PhysicsSystem(float fixedDeltaTime) : m_physicsWorld(std::make_unique<Physics::CollisionHandler>()) {
        m_physicsWorld.setFixedDeltaTime(fixedDeltaTime);
    }

    namespace Physics {

        auto PhysicsSystem::addRectangles(ComponentManager::ComponentsContainer& rectangles, std::vector<Body*>& bodies) -> void {
            for (auto component : rectangles) {
                auto collider = static_cast<BoxColliderComponent*>(component.second);
                BodyDefinition bodyDef;
                bodyDef.id = collider->getEntityId();
                bodyDef.shape = std::make_unique<Rectangle>(collider->size);
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
        }

        auto PhysicsSystem::addCircles(ComponentManager::ComponentsContainer& circles, std::vector<Body*>& bodies) -> void {
            for (auto component : circles) {
                auto collider = static_cast<CircleColliderComponent*>(component.second);
                BodyDefinition bodyDef;
                bodyDef.id = collider->getEntityId();
                bodyDef.shape = std::make_unique<Circle>(collider->radius);
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
        }

        auto PhysicsSystem::processContactEvents(ComponentManager::ComponentsContainer& colliders) -> void {
            for (auto event : m_contactEvents) {
                switch (event.bodyA->getShapeType()) {
                    case ShapeType::circle:
                        static_cast<CircleColliderComponent*>(colliders.at(event.bodyA->getID()));
                        break;
                    case ShapeType::rectangle:
                        static_cast<BoxColliderComponent*>(colliders.at(event.bodyA->getID()));
                        break;
                }
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
            using AnimeDefendersEngine::Math::Vector2f;

            ComponentManager& componentManager = sceneManager.getActiveScene().getComponentManager();
            auto boxes = componentManager.getComponents<BoxColliderComponent>();
            auto circles = componentManager.getComponents<CircleColliderComponent>();

            std::vector<Body*> bodies;
            bodies.reserve(boxes.size() + circles.size());

            ComponentManager::ComponentsContainer colliders;
            colliders.merge(boxes);
            colliders.merge(circles);

            addRectangles(boxes, bodies);
            addCircles(circles, bodies);

            m_physicsWorld.setFixedDeltaTime(fixedDeltaTime);
            m_contactEvents = m_physicsWorld.fixedUpdate();

            for (const auto& body : bodies) {
                switch (body->getShapeType()) {
                    case ShapeType::circle:
                        static_cast<CircleColliderComponent*>(circles.at(body->getID()))->transformComponent.position = body->getPosition();
                        break;
                    case ShapeType::rectangle:
                        static_cast<BoxColliderComponent*>(boxes.at(body->getID()))->transformComponent.position = body->getPosition();
                        break;
                }
            }

            processContactEvents(colliders);
        }

        auto PhysicsSystem::setFixedDeltaTime(float fixedDeltaTime) noexcept -> void {
            m_physicsWorld.setFixedDeltaTime(fixedDeltaTime);
        }

    }  // namespace Physics

}  // namespace AnimeDefendersEngine
