#include "ColliderComponent.hpp"
#include "RigidBodyComponent.hpp"
#include "TransformComponent.hpp"

namespace AnimeDefendersEngine {

    ColliderComponent::ColliderComponent(const std::string& entityId, ComponentManager& compManager, Math::Vector2f size, bool isTrigger,
                                         CollisionFunction onCollisionEnter, CollisionFunction onCollisionStay,
                                         CollisionFunction onCollisionExit, TransformComponent& transformComponent,
                                         RigidBodyComponent* rigidBodyComponent)
        : BaseComponent<ColliderComponent>(entityId, compManager),
          m_size(size),
          m_isTrigger(isTrigger),
          m_onCollisionEnter(onCollisionEnter),
          m_onCollisionStay(onCollisionStay),
          m_onCollisionExit(onCollisionExit),
          m_rigidBodyComponent(rigidBodyComponent),
          m_transformComponent(transformComponent) {
        m_shapeType = Physics::ShapeType::rectangle;
    }

    ColliderComponent::ColliderComponent(const std::string& entityId, ComponentManager& compManager, float radius, bool isTrigger,
                                         CollisionFunction onCollisionEnter, CollisionFunction onCollisionStay,
                                         CollisionFunction onCollisionExit, TransformComponent& transformComponent,
                                         RigidBodyComponent* rigidBodyComponent)
        : BaseComponent<ColliderComponent>(entityId, compManager),
          m_radius(radius),
          m_isTrigger(isTrigger),
          m_onCollisionEnter(onCollisionEnter),
          m_onCollisionStay(onCollisionStay),
          m_onCollisionExit(onCollisionExit),
          m_rigidBodyComponent(rigidBodyComponent),
          m_transformComponent(transformComponent) {
        m_shapeType = Physics::ShapeType::circle;
    }

    auto ColliderComponent::onCollisionEnter(ColliderComponent& collider) -> void {
        m_onCollisionEnter(collider);
    }

    auto ColliderComponent::onCollisionStay(ColliderComponent& collider) -> void {
        m_onCollisionStay(collider);
    }

    auto ColliderComponent::onCollisionExit(ColliderComponent& collider) -> void {
        m_onCollisionExit(collider);
    }

    auto ColliderComponent::getTransform() const noexcept -> TransformComponent& {
        return m_transformComponent;
    }

    auto ColliderComponent::getRigidBody() const noexcept -> RigidBodyComponent* {
        return m_rigidBodyComponent;
    }

    auto ColliderComponent::getShapeType() const noexcept -> Physics::ShapeType {
        return m_shapeType;
    }

    auto ColliderComponent::getSize() const noexcept -> Math::Vector2f {
        return m_size;
    }

    auto ColliderComponent::getRadius() const noexcept -> float {
        return m_radius;
    }

    auto ColliderComponent::isTrigger() const noexcept -> bool {
        return m_isTrigger;
    }

}  // namespace AnimeDefendersEngine
