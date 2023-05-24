#pragma once

#include "ContactEvent.hpp"
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
        auto addRectangles(AnimeDefendersEngine::ComponentManager::ComponentsContainer& rectangles, std::vector<Body*>& bodies) -> void;
        auto addCircles(AnimeDefendersEngine::ComponentManager::ComponentsContainer& circles, std::vector<Body*>& bodies) -> void;
        auto processContactEvents(ComponentManager::ComponentsContainer& colliders) -> void;

        PhysicsWorld m_physicsWorld;
        std::vector<ContactEvent> m_contactEvents;
    };

}  // namespace AnimeDefendersEngine::Physics
