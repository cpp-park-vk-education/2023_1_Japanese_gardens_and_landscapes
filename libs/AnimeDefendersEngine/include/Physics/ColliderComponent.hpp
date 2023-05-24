#pragma once

#include "BaseComponent.hpp"
#include "ComponentManager.hpp"
#include "RigidBodyComponent.hpp"
#include "Shape.hpp"
#include "TransformComponent.hpp"
#include "Vector2.hpp"

#include <memory>

namespace AnimeDefendersEngine {

    class ColliderComponent : public BaseComponent<ColliderComponent> {
     public:
        ColliderComponent(const std::string& entityId, ComponentManager& compManager, Math::Vector2f size,
                          TransformComponent& transfromComponent, RigidBodyComponent* rigidBodyComponent = nullptr);
        ColliderComponent(const std::string& entityId, ComponentManager& compManager, float radius, TransformComponent& transfromComponent,
                          RigidBodyComponent* rigidBodyComponent = nullptr);

        RigidBodyComponent* rigidBodyComponent{nullptr};
        TransformComponent& transformComponent;
        Physics::ShapeType shapeType;
        Math::Vector2f size;
        float radius{};
    };

}  // namespace AnimeDefendersEngine
