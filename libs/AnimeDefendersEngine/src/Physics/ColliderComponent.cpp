#include "ColliderComponent.hpp"
#include "RigidBodyComponent.hpp"
#include "TransformComponent.hpp"

namespace AnimeDefendersEngine {

    ColliderComponent::ColliderComponent(const std::string& entityId, ComponentManager& compManager, Math::Vector2f size,
                                         TransformComponent& transformComponent, RigidBodyComponent* rigidBodyComponent)
        : BaseComponent<ColliderComponent>(entityId, compManager),
          m_size(size),
          m_rigidBodyComponent(rigidBodyComponent),
          m_transformComponent(transformComponent) {
        m_shapeType = Physics::ShapeType::rectangle;
    }

    ColliderComponent::ColliderComponent(const std::string& entityId, ComponentManager& compManager, float radius,
                                         TransformComponent& transformComponent, RigidBodyComponent* rigidBodyComponent)
        : BaseComponent<ColliderComponent>(entityId, compManager),
          m_radius(radius),
          m_rigidBodyComponent(rigidBodyComponent),
          m_transformComponent(transformComponent) {
        m_shapeType = Physics::ShapeType::circle;
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

}  // namespace AnimeDefendersEngine
