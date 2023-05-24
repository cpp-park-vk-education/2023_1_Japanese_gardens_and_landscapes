#pragma once

#include <vector>

namespace AnimeDefendersEngine {

    class SceneManager;
    class ISystem;

}  // namespace AnimeDefendersEngine

#include <vector>

namespace AnimeDefendersEngine {

    class ISystemManager {
     public:
        virtual void updateSystems(SceneManager& sceneManager, float fixedDeltaTime) = 0;
        ~ISystemManager(){};
    };

    class SystemManager : public ISystemManager {
     public:
        void updateSystems(SceneManager& sceneManager, float fixedDeltaTime) override;

     private:
        std::vector<ISystem*> m_systems;
    };

}  // namespace AnimeDefendersEngine
