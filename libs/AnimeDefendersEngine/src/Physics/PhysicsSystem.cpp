#include "PhysicsSystem.hpp"
#include "Body.hpp"
#include "BodyDefinition.hpp"
#include "CollisionHandler.hpp"
#include "Component.hpp"
#include "ComponentManager.hpp"
#include "ContactEvent.hpp"
#include "Scene.hpp"
#include "SceneManager.hpp"

#include <memory>

namespace AnimeDefendersEngine::Physics {

    PhysicsSystem::PhysicsSystem(float fixedDeltaTime) : m_physicsWorld(std::make_unique<CollisionHandler>()) {
        m_physicsWorld.setFixedDeltaTime(fixedDeltaTime);
    }

    auto PhysicsSystem::addBodies(ComponentManager::ComponentsContainer& components) -> std::vector<Body*> {}

    auto PhysicsSystem::processContactEvents(ComponentManager::ComponentsContainer& colliders) -> void {}

    auto PhysicsSystem::updateSystem(SceneManager& sceneManager, float fixedDeltaTime) -> void {}

    auto PhysicsSystem::setFixedDeltaTime(float fixedDeltaTime) noexcept -> void {
        m_physicsWorld.setFixedDeltaTime(fixedDeltaTime);
    }

}  // namespace AnimeDefendersEngine::Physics
