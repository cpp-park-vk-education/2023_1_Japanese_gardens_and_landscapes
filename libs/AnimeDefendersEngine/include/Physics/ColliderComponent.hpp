#pragma once

#include "BaseComponent.hpp"
#include "ComponentManager.hpp"
#include "Shape.hpp"
#include "Vector2.hpp"

#include <functional>
#include <memory>

namespace AnimeDefendersEngine {

    class ColliderComponent;
    class TransformComponent;
    class RigidBodyComponent;

}  // namespace AnimeDefendersEngine

namespace AnimeDefendersEngine {

    using CollisionFunction = std::function<void(ColliderComponent&)>;

    class ColliderComponent : public BaseComponent<ColliderComponent> {
     public:
        ColliderComponent(const std::string& entityId, ComponentManager& compManager, Math::Vector2f size, bool isTrigger,
                          CollisionFunction onCollisionEnter, CollisionFunction onCollisionStay, CollisionFunction onCollisionExit,
                          TransformComponent& transfromComponent, RigidBodyComponent* rigidBodyComponent = nullptr);
        ColliderComponent(const std::string& entityId, ComponentManager& compManager, float radius, bool isTrigger,
                          CollisionFunction onCollisionEnter, CollisionFunction onCollisionStay, CollisionFunction onCollisionExit,
                          TransformComponent& transfromComponent, RigidBodyComponent* rigidBodyComponent = nullptr);

        auto onCollisionEnter(ColliderComponent& collider) -> void;
        auto onCollisionStay(ColliderComponent& collider) -> void;
        auto onCollisionExit(ColliderComponent& collider) -> void;

        [[nodiscard]] auto getTransform() const noexcept -> TransformComponent&;
        [[nodiscard]] auto getRigidBody() const noexcept -> RigidBodyComponent*;
        [[nodiscard]] auto getShapeType() const noexcept -> Physics::ShapeType;
        [[nodiscard]] auto getSize() const noexcept -> Math::Vector2f;
        [[nodiscard]] auto getRadius() const noexcept -> float;
        [[nodiscard]] auto isTrigger() const noexcept -> bool;

     private:
        RigidBodyComponent* m_rigidBodyComponent{nullptr};
        TransformComponent& m_transformComponent;
        CollisionFunction m_onCollisionEnter;
        CollisionFunction m_onCollisionStay;
        CollisionFunction m_onCollisionExit;
        bool m_isTrigger;
        Physics::ShapeType m_shapeType;
        Math::Vector2f m_size;
        float m_radius{};
    };

}  // namespace AnimeDefendersEngine
