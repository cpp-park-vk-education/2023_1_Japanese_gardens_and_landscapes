#pragma once

#include "ISystem.hpp"

namespace AnimeDefendersEngine {
    namespace PhysicsEngine {
        class PhysicsSystem : public ISystem {
         public:
            virtual void updateSystem(ComponentManager&) override{};

         private:
            PhysicsWorld physicsWorld;
        }
    }  // namespace PhysicsEngine
}  // namespace AnimeDefendersEngine