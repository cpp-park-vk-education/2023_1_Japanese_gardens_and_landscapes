#pragma once

// Пока что только прямоугольник

#include "BaseComponent.hpp"
#include "Component.hpp"
#include "ComponentManager.hpp"
#include "RigidBody2DComponent.hpp"
#include "TransformComponent.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine {

    class Collider2DComponent : public AnimeDefendersEngine::BaseComponent<Collider2DComponent> {
     public:
        Collider2DComponent(const std::string& entityId, AnimeDefendersEngine::ComponentManager& compManager,
                            AnimeDefendersEngine::Math::Vector2<float> size, TransformComponent& transfromComponent,
                            RigidBody2DComponent* rigidBody2DComponent = nullptr)
            : AnimeDefendersEngine::BaseComponent<Collider2DComponent>(entityId, compManager),
              size(size),
              rigidBody2DComponent(rigidBody2DComponent),
              transformComponent(transformComponent) {}

        AnimeDefendersEngine::Math::Vector2<float> size;
        RigidBody2DComponent* rigidBody2DComponent;
        TransformComponent& transformComponent;
    };

}  // namespace AnimeDefendersEngine