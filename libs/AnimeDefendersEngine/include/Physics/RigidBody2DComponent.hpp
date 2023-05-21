#pragma once

#include "BaseComponent.hpp"
#include "Component.hpp"
#include "ComponentManager.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine {

    constexpr float defaultMass = 1.f;

    class RigidBody2DComponent : public AnimeDefendersEngine::BaseComponent<RigidBody2DComponent> {
     public:
        RigidBody2DComponent(const std::string& entityId, AnimeDefendersEngine::ComponentManager& compManager, float mass = defaultMass,
                             AnimeDefendersEngine::Math::Vector2<float> velocity = AnimeDefendersEngine::Math::Vector2<float>(0, 0))
            : AnimeDefendersEngine::BaseComponent<RigidBody2DComponent>(entityId, compManager), mass(mass), velocity(velocity) {}

        AnimeDefendersEngine::Math::Vector2<float> velocity;
        float mass;
    };

}  // namespace AnimeDefendersEngine
