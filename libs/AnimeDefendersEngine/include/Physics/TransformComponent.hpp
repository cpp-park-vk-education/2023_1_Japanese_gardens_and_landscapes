#pragma once

#include "BaseComponent.hpp"
#include "Component.hpp"
#include "ComponentManager.hpp"
#include "RigidBodyComponent.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine {

    class TransformComponent : public BaseComponent<TransformComponent> {
     public:
        TransformComponent(const std::string& entityId, ComponentManager& compManager, Math::Vector2f position)
            : BaseComponent<TransformComponent>(entityId, compManager), position(position) {}

        Math::Vector2f position;
    };

}  // namespace AnimeDefendersEngine
