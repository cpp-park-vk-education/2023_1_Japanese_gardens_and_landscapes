#pragma once

// static_assert(false, "Need to add propper headers for IEventManager and InputManager");
#include "InputManager.hpp"
#include "SystemManager.hpp"

#include <memory>

namespace AnimeDefendersEngine {

    class GameLoop {
     public:
        void run();
        void setSystemManager(std::unique_ptr<ISystemManager>);
        void setEventManager(std::unique_ptr<EventManager>);

     private:
        bool is_running{true};
        std::unique_ptr<ISystemManager> m_systemManager;
    };

}  // namespace AnimeDefendersEngine
