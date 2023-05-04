#pragma once

static_assert(false, "Need to add propper headers for IEventManager and InputManager");
#include "SceneManager.hpp"
#include "SystemManager.hpp"

#include <memory>

namespace AnimeDefendersEngine {
    class GameLoop {
     public:
        void run();
        void setSystemManager(std::unique_ptr<ISystemManager>);
        void setEventManager(std::unique_ptr<IEventManager>);
        void setSceneManager(std::shared_ptr<ISceneManager>);

     private:
        bool is_running = true;
        std::shared_ptr<ISceneManager> m_sceneManager{nullptr};
        std::unique_ptr<ISystemManager> m_systemManager{nullptr};
        std::unique_ptr<IEventManager> m_eventManager{nullptr};
        std::unique_ptr<InputManager> m_input{nullptr};
    };
}  // namespace AnimeDefendersEngine