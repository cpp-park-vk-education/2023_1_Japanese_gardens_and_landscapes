#pragma once

#include "ISystem.hpp"
#include "PhysicsWorld.hpp"
#include "SceneManager.hpp"

namespace AnimeDefendersEngine::Physics {

    class PhysicsSystem : public ISystem {
     public:
        explicit PhysicsSystem(float fixedDeltaTime);
        auto updateSystem(SceneManager& sceneManager, float timeStep) -> void;
        auto setFixedDeltaTime(float fixedDeltaTime) noexcept -> void;

     private:
        PhysicsWorld m_physicsWorld;
    };

}  // namespace AnimeDefendersEngine::Physics
