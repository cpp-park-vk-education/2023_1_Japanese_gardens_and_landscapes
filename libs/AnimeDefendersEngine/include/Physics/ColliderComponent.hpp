#pragma once

#include "BaseComponent.hpp"
#include "Component.hpp"
#include "ComponentManager.hpp"
#include "RigidBodyComponent.hpp"
#include "TransformComponent.hpp"
#include "Vector2.hpp"

#include <memory>

namespace AnimeDefendersEngine {

    class BoxColliderComponent : public BaseComponent<BoxColliderComponent> {
     public:
        BoxColliderComponent(const std::string& entityId, ComponentManager& compManager, Math::Vector2f size,
                             TransformComponent& transfromComponent, RigidBodyComponent* rigidBodyComponent = nullptr)
            : BaseComponent<BoxColliderComponent>(entityId, compManager),
              size(size),
              rigidBodyComponent(rigidBodyComponent),
              transformComponent(transformComponent) {}

        auto makeShape() { return std::make_unique<Physics::Rectangle>(size); }

        Math::Vector2f size;
        RigidBodyComponent* rigidBodyComponent;
        TransformComponent& transformComponent;
    };

    class CircleColliderComponent : public BaseComponent<CircleColliderComponent> {
     public:
        CircleColliderComponent(const std::string& entityId, ComponentManager& compManager, Math::Vector2f size,
                                TransformComponent& transfromComponent, RigidBodyComponent* rigidBodyComponent = nullptr)
            : BaseComponent<CircleColliderComponent>(entityId, compManager),
              radius(radius),
              rigidBodyComponent(rigidBodyComponent),
              transformComponent(transformComponent) {}

        auto makeShape() { return std::make_unique<Physics::Circle>(radius); }

        float radius;
        RigidBodyComponent* rigidBodyComponent;
        TransformComponent& transformComponent;
    };

}  // namespace AnimeDefendersEngine