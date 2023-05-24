#pragma once

#include "BaseComponent.hpp"
#include "ComponentManager.hpp"
#include "Shape.hpp"
#include "Vector2.hpp"

#include <memory>

namespace AnimeDefendersEngine {

    class TransformComponent;
    class RigidBodyComponent;

}  // namespace AnimeDefendersEngine

namespace AnimeDefendersEngine {

    class ColliderComponent : public BaseComponent<ColliderComponent> {
     public:
        ColliderComponent(const std::string& entityId, ComponentManager& compManager, Math::Vector2f size,
                          TransformComponent& transfromComponent, RigidBodyComponent* rigidBodyComponent = nullptr);
        ColliderComponent(const std::string& entityId, ComponentManager& compManager, float radius, TransformComponent& transfromComponent,
                          RigidBodyComponent* rigidBodyComponent = nullptr);

        [[nodiscard]] auto getTransform() const noexcept -> TransformComponent&;
        [[nodiscard]] auto getRigidBody() const noexcept -> RigidBodyComponent*;
        [[nodiscard]] auto getShapeType() const noexcept -> Physics::ShapeType;
        [[nodiscard]] auto getSize() const noexcept -> Math::Vector2f;
        [[nodiscard]] auto getRadius() const noexcept -> float;

     private:
        RigidBodyComponent* m_rigidBodyComponent{nullptr};
        TransformComponent& m_transformComponent;
        Physics::ShapeType m_shapeType;
        Math::Vector2f m_size;
        float m_radius{};
    };

}  // namespace AnimeDefendersEngine
