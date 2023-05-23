#pragma once

#include "BaseComponent.hpp"
#include "Component.hpp"
#include "ComponentManager.hpp"
#include "RigidBody2DComponent.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine {

    class TransformComponent : public BaseComponent<TransformComponent> {
     public:
        TransformComponent(const std::string& entityId, ComponentManager& compManager, Math::Vector2<float> position)
            : BaseComponent<TransformComponent>(entityId, compManager), position(position) {}

        Math::Vector2f position;
    };

}  // namespace AnimeDefendersEngine
