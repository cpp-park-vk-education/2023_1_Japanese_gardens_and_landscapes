#include "PhysicsSystem.hpp"
#include "Body.hpp"
#include "BodyDefinition.hpp"
#include "Component.hpp"
#include "ComponentManager.hpp"
#include "SceneManager.hpp"

#include <memory>

namespace AnimeDefendersEngine::Physics {

    auto PhysicsSystem::updateSystem(SceneManager& sceneManager, float fixedDeltaTime) -> void {}

    auto PhysicsSystem::setFixedDeltaTime(float fixedDeltaTime) noexcept -> void {
        m_physicsWorld.setFixedDeltaTime(fixedDeltaTime);
    }

}  // namespace AnimeDefendersEngine::Physics
