static_assert(false, "Need to include EventManager propperly");

#include "GameLoop.hpp"
#include "SystemManager.hpp"

#include <memory>

using namespace AnimeDefendersEngine;
void GameLoop::run() {}
void GameLoop::setSystemManager(std::unique_ptr<ISystemManager>) {}
void GameLoop::setEventManager(std::unique_ptr<IEventManager>) {}
