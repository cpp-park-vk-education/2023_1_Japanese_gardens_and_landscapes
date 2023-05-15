// static_assert(false, "Need to include EventManager properly");

#include "EventManager.hpp"
#include "GameLoop.hpp"
#include "SystemManager.hpp"

using namespace AnimeDefendersEngine;

void GameLoop::run() {}

void GameLoop::setSystemManager(std::unique_ptr<ISystemManager>) {}

void GameLoop::setEventManager(std::unique_ptr<IEventManager>) {}
