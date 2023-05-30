#pragma once

#include "ComponentManager.hpp"
#include "ContactEvent.hpp"
#include "ISystem.hpp"
#include "PhysicsWorld.hpp"
#include "SceneManager.hpp"

namespace AnimeDefendersEngine::Physics {

    class PhysicsSystem : public ISystem {
     public:
        explicit PhysicsSystem();
        explicit PhysicsSystem(float fixedDeltaTime, float maxDeltaTime);
        auto setFixedDeltaTime(float fixedDeltaTime) noexcept -> void;
        auto updateSystem(SceneManager& sceneManager, float timeStep) -> void;
        auto updateSystem(SceneManager&) -> void override{};

     private:
        [[nodiscard]] auto addBodies(ComponentManager::ComponentsContainer& components) -> std::vector<Body*>;
        auto processContactEvents(ComponentManager::ComponentsContainer& components) -> void;

     private:
        PhysicsWorld m_physicsWorld;
        std::vector<ContactEvent> m_contactEvents;
    };

}  // namespace AnimeDefendersEngine::Physics
