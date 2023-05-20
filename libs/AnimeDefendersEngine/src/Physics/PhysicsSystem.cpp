#include "PhysicsSystem.hpp"
#include <memory>
#include "BaseComponent.hpp"
#include "Body.hpp"
#include "BodyDefinition.hpp"
#include "Component.hpp"
#include "ComponentManager.hpp"
using namespace AnimeDefendersEngine::Physics;

class RigidBody2DComponent : public AnimeDefendersEngine::BaseComponent<RigidBody2DComponent> {
 public:
    RigidBody2DComponent(AnimeDefendersEngine::ComponentManager& compManager)
        : AnimeDefendersEngine::BaseComponent<RigidBody2DComponent>(compManager) {}

    AnimeDefendersEngine::Math::Vector2f velocity;
};

class Collider2DComponent : public AnimeDefendersEngine::BaseComponent<Collider2DComponent> {
 public:
    Collider2DComponent(AnimeDefendersEngine::ComponentManager& compManager)
        : AnimeDefendersEngine::BaseComponent<Collider2DComponent>(compManager) {}

    AnimeDefendersEngine::Math::Vector2f size;
    RigidBody2DComponent* rigidBody2DComponent;
    TransformComponent* transformComponent;
};

// У коллайдера ссылка на трансформ и риджид бади

auto PhysicsSystem::updateSystem(SceneManager& sceneManager, float fixedDeltaTime) -> void {
    using AnimeDefendersEngine::Math::Vector2f;

    ComponentManager& componentManager = sceneManager.getActiveScene().getComponentManager();
    auto colliders = componentManager.getComponents<Collider2DComponent>();

    std::vector<Body*> bodies;
    bodies.reserve(colliders.size());
    for (auto collider : colliders) {
        BodyDefinition bodyDef;
        bodyDef.id = collider.getEntityID();
        bodyDef.shape = std::make_unique<Rectangle>(collider.size);
        bodyDef.transform.position = collider.transformComponent.position;

        Body* body = m_physicsWorld.addBody(std::move(bodyDef));

        if (collider.rigidBody2DComponent == nullptr) {
            body->setType(BodyType::staticBody);
        } else {
            body->setType(BodyType::dynamicBody);
            body->applyImpulse(collider.rigidBody2DComponent.velocity);
        }

        bodies.push_back(body);
    }

    m_physicsWorld.setFixedDeltaTime(fixedDeltaTime);
    m_physicsWorld.fixedUpdate();

    for (auto body : bodies) {
        colliders.at(body->getID()).transformComponent.position = body->getPosition();
    }
}

auto PhysicsSystem::setFixedDeltaTime(float fixedDeltaTime) noexcept -> void {
    m_physicsWorld.setFixedDeltaTime(fixedDeltaTime);
}
