#include "SystemManager.hpp"
#include "ComponentManager.hpp"
#include "ISystem.hpp"
#include "PhysicsSystem.hpp"

namespace AnimeDefendersEngine {

    SystemManager::SystemManager() {
        m_systems.push_back(std::make_unique<Physics::PhysicsSystem>());
    }

    auto SystemManager::updateSystems(SceneManager& sceneManager, float fixedDeltaTime) -> void {
        static_cast<Physics::PhysicsSystem*>(m_systems.at(0).get())->updateSystem(sceneManager, fixedDeltaTime);
    }

}  // namespace AnimeDefendersEngine
