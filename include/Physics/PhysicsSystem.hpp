#pragma once

#include "ISystem.hpp"

namespace AnimeDefendersEngine {
    namespace PhysicsEngine {
        class PhysicsSystem : public ISystem {
         public:
            virtual auto updateSystem(ComponentManager& componentManager) -> void override{};
            virtual auto updateSystem(ComponentManager& componentManager, float timeStep) -> void override{};

         private:
            PhysicsWorld physicsWorld;
        }
    }  // namespace PhysicsEngine
}  // namespace AnimeDefendersEngine