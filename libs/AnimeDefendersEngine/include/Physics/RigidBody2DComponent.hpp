#pragma once

#include "BaseComponent.hpp"
#include "Component.hpp"
#include "ComponentManager.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine {

    constexpr float defaultMass = 1.f;

    class RigidBody2DComponent : public BaseComponent<RigidBody2DComponent> {
     public:
        RigidBody2DComponent(const std::string& entityId, ComponentManager& compManager, float mass = defaultMass,
                             Math::Vector2f velocity = Math::Vector2f())
            : BaseComponent<RigidBody2DComponent>(entityId, compManager), mass(mass), velocity(velocity) {}

        Math::Vector2f velocity;
        float mass;
    };

}  // namespace AnimeDefendersEngine
