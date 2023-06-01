#pragma once

#include "ISystem.hpp"
#include "ISystemManager.hpp"

#include <memory>
#include <vector>

namespace AnimeDefendersEngine {

    class SceneManager;

}  // namespace AnimeDefendersEngine

namespace AnimeDefendersEngine {

    class SystemManager : public ISystemManager {
     public:
        SystemManager();
        auto updateSystems(SceneManager& sceneManager, float fixedDeltaTime) -> void override;

     private:
        std::vector<std::unique_ptr<ISystem>> m_systems;
    };

}  // namespace AnimeDefendersEngine
