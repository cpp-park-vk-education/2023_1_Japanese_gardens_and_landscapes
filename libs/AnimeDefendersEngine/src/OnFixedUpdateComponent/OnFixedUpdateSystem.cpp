#include "OnFixedUpdateSystem.hpp"
#include "OnFixedUpdateComponent.hpp"
#include "Scene.hpp"

namespace AnimeDefendersEngine {

    auto OnFixedUpdateSystem::updateSystem(SceneManager& sceneManager) -> void {
        auto components = sceneManager.getActiveScene().getComponentManager().getComponents<OnFixedUpdateComponent>();
        for (const auto& [entityId, component] : components) {
            auto* onUpdateComponent = static_cast<OnFixedUpdateComponent*>(component);
            onUpdateComponent->onFixedUpdate();
        }
    }

}  // namespace AnimeDefendersEngine
