#include "PhysicsSystem.hpp"
// #include "BaseComponent.hpp"
#include <memory>
#include "Body.hpp"
#include "BodyDefinition.hpp"
#include "Component.hpp"
#include "ComponentManager.hpp"
using namespace AnimeDefendersEngine::Physics;

// class PhysicsComponent : public AnimeDefendersEngine::BaseComponent<PhysicsComponent> {
//  public:
//     PhysicsComponent(AnimeDefendersEngine::ComponentManager& compManager)
//         : AnimeDefendersEngine::BaseComponent<PhysicsComponent>(compManager) {

//     }
//     bool isStatic{false};

// };

// У коллайдера ссылка на трансформ и риджид бади

auto PhysicsSystem::updateSystem(SceneManager& sceneManager, float fixedDeltaTime) -> void {
    using AnimeDefendersEngine::Math::Vector2f;

    ComponentManager& componentManager = sceneManager.getActiveScene()->getComponentManager();
    auto components = componentManager.getComponents<Collider2DComponent>();

    std::vector<Body*> bodies;
    bodies.reserve(components.size());
    for (auto component : components) {
        BodyDefinition bodyDef;
        bodyDef.id = component.getEntityID();
        bodyDef.shape = std::make_unique<Rectangle>(Collider2DComponent.size);
        bodyDef.transform.position = component.TransformComponent.position;

        Body* body = m_physicsWorld.addBody(std::move(bodyDef));

        if (component.RigidBody2DComponent == nullptr) {
            body->setType(BodyType::staticBody);
        } else {
            body->setType(BodyType::dynamicBody);
            body->applyImpulse(component.RigidBody2DComponent.velocity);
        }

        bodies.push_back(body);
    }

    m_physicsWorld.setFixedDeltaTime(fixedDeltaTime);
    m_physicsWorld.fixedUpdate();

    for (auto body : bodies) {
        components.at(body->getID()).TransformComponent.position = body->getPosition();
    }
}

auto PhysicsSystem::setFixedDeltaTime(float fixedDeltaTime) noexcept -> void {
    m_physicsWorld.setFixedDeltaTime(fixedDeltaTime);
}
