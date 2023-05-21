#pragma once

#include "BaseComponent.hpp"
#include "Component.hpp"
#include "ComponentManager.hpp"
#include "RigidBody2DComponent.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine {

    class TransformComponent : public AnimeDefendersEngine::BaseComponent<TransformComponent> {
     public:
        TransformComponent(const std::string& entityId, AnimeDefendersEngine::ComponentManager& compManager,
                           AnimeDefendersEngine::Math::Vector2<float> position)
            : AnimeDefendersEngine::BaseComponent<TransformComponent>(entityId, compManager), position(position) {}

        AnimeDefendersEngine::Math::Vector2<float> position;
    };

}  // namespace AnimeDefendersEngine
