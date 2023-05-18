#pragma once

// static_assert(false, "Need to add propper headers for IEventManager and InputManager");
#include "InputManager.hpp"
#include "Renderer.hpp"
#include "SceneManager.hpp"
#include "SystemManager.hpp"

#include <memory>

namespace AnimeDefendersEngine {

    class GameLoop {
     public:
        void run();
        void setSystemManager(std::unique_ptr<ISystemManager>);
        void setEventManager(std::unique_ptr<IEventManager>);

     private:
        bool m_isRunning{true};
        float m_maxDeltaTime{1.0f / 25.0f};
        float m_fixedDeltaTime{1.0f / 60.0f};

        std::unique_ptr<ISystemManager> m_systemManager;
        std::unique_ptr<IEventManager> m_eventManager;
        std::unique_ptr<InputManager> m_inputManager;
        std::unique_ptr<Graphics::Renderer> m_renderer;

        SceneManager* m_sceneManager;
        ComponentManager* m_componentManager;
    };

}  // namespace AnimeDefendersEngine
