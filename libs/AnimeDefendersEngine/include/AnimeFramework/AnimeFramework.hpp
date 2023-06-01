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
        SceneManager m_sceneManager;
        ComponentManager m_globalComponentsManager;
        GameLoop m_gameLoop;
    };
}  // namespace AnimeDefendersEngine
