#include "PhysicsSystem.hpp"
#include "Body.hpp"
#include "BodyDefinition.hpp"
#include "Component.hpp"
#include "ComponentManager.hpp"
#include "SceneManager.hpp"

#include <memory>

using namespace AnimeDefendersEngine;

auto Physics::PhysicsSystem::updateSystem(SceneManager& sceneManager, float fixedDeltaTime) -> void {}

auto Physics::PhysicsSystem::setFixedDeltaTime(float fixedDeltaTime) noexcept -> void {
    m_physicsWorld.setFixedDeltaTime(fixedDeltaTime);
}
