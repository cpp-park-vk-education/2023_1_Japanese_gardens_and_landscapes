#include "OnFixedUpdateSystem.hpp"
#include "OnFixedUpdateComponent.hpp"
#include "Scene.hpp"

namespace AnimeDefendersEngine {

    auto OnFixedUpdateSystem::updateSystem(SceneManager& sceneManager) -> void {
        auto components = sceneManager.getActiveScene().getComponentManager().getComponents<OnFixedUpdateComponent>();
        for (const auto& component : components) {
            auto* onUpdateComponent = static_cast<OnFixedUpdateComponent*>(component.second);
            onUpdateComponent->onFixedUpdate();
        }
    }

}  // namespace AnimeDefendersEngine
