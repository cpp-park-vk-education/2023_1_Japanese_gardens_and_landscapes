#pragma once

#include "ISystem.hpp"
#include "PhysicsWorld.hpp"

namespace AnimeDefendersEngine {
    namespace PhysicsEngine {

        class PhysicsSystem : public ISystem {
         public:
            explicit PhysicsSystem(float fixedDeltaTime);
            virtual auto updateSystem(ComponentManager& componentManager) -> void override;
            auto updateSystem(ComponentManager& componentManager, float timeStep) -> void;
            auto setFixedDeltaTime(float fixedDeltaTime) -> void;

         private:
            PhysicsWorld physicsWorld;
        };

    }  // namespace PhysicsEngine
}  // namespace AnimeDefendersEngine
