#pragma once

#include "ISystemManager.hpp"

#include <vector>

namespace AnimeDefendersEngine {

    class SceneManager;
    class ISystem;

}  // namespace AnimeDefendersEngine

namespace AnimeDefendersEngine {

    class SystemManager : public ISystemManager {
     public:
        void updateSystems(SceneManager& sceneManager, float fixedDeltaTime) override;

     private:
        std::vector<ISystem*> m_systems;
    };

}  // namespace AnimeDefendersEngine
