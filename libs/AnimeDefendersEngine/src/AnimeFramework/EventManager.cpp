#include "EventManager.hpp"

using namespace AnimeDefendersEngine;

auto EventManager::addListener(IEventListener& listener) -> void{
    eventListeners.insert({listener});
};
