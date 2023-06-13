#pragma once

#include "ComponentManager.hpp"
#include "GameLoop.hpp"
#include "SceneManager.hpp"

namespace AnimeDefendersEngine {

    class AnimeFramework {
     public:
        void run();
        /* {
                m_sceneManager = initializer.makeSceneManager(file);
                m_componentManager = initializer.makeSceneManager(file);
                GameLoop.run();
        } */

     private:
        std::unique_ptr<ISceneManager> m_sceneManager;
        std::unique_ptr<IComponentManager> m_componentManager;
        GameLoop m_gameloop;
    };
}  // namespace AnimeDefendersEngine
