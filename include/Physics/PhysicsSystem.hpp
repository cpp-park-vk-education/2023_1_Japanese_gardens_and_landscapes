#pragma once

#include "ISystem.hpp"

namespace AnimeDefendersEngine {
    namespace PhysicsEngine {
        class PhysicsSystem : public ISystem {
         public:
            virtual auto updateSystem(ComponentManager&) -> void override{};

         private:
            PhysicsWorld physicsWorld;
        }
    }  // namespace PhysicsEngine
}  // namespace AnimeDefendersEngine