#pragma once

#include "ISystem.hpp"
#include "PhysicsWorld.hpp"

namespace AnimeDefendersEngine::Physics {

    class PhysicsSystem : public ISystem {
     public:
        explicit PhysicsSystem(float fixedDeltaTime);
        virtual auto updateSystem(ComponentManager& componentManager) -> void override final;
        auto updateSystem(ComponentManager& componentManager, float timeStep) -> void;
        auto setFixedDeltaTime(float fixedDeltaTime) noexcept -> void;

     private:
        PhysicsWorld physicsWorld;
    };

}  // namespace AnimeDefendersEngine::Physics
