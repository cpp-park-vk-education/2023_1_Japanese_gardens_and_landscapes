#pragma once

#include <functional>
#include "Event.hpp"

namespace AnimeDefendersEngine::EventManager {
    class EventListener {
     public:
        explicit EventListener(const std::function<void()>& function, const std::string& name)
            : listenerFunction(function), eventListenerName(name) {}
        auto getName() const -> const std::string&;
        auto getFunction() -> std::function<void()>;

     private:
        std::string eventListenerName;
        std::function<void()> listenerFunction;
    };

}  // namespace AnimeDefendersEngine::EventManager
