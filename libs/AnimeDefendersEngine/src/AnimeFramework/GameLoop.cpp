// static_assert(false, "Need to include EventManager properly");

#include "GameLoop.hpp"
#include "EventManager.hpp"
#include "SystemManager.hpp"

using namespace AnimeDefendersEngine;

GameLoop::GameLoop(std::unique_ptr<ISystemManager>&& systemManager, std::unique_ptr<IEventManager>&& eventManager,
                   std::unique_ptr<InputManager>&& inputManager, std::unique_ptr<Graphics::Renderer>&& renderer, SceneManager* sceneManager,
                   ComponentManager* componentManager, float fixedDeltaTime, float maxDeltaTime)
    : m_sceneManager(sceneManager),
      m_componentManager(componentManager),
      m_fixedDeltaTime(fixedDeltaTime),
      m_maxDeltaTime(maxDeltaTime),
      m_isRunning(true) {
    setSystemManager(std::move(systemManager));
    setEventManager(std::move(eventManager));
    setInputManager(std::move(inputManager));
    setRenderer(std::move(renderer));
}

auto GameLoop::run() -> void {}

auto GameLoop::setSystemManager(std::unique_ptr<ISystemManager>&& systemManager) -> void {
    m_systemManager = std::move(systemManager);
}

auto GameLoop::setEventManager(std::unique_ptr<IEventManager>&& eventManager) -> void {
    m_eventManager = std::move(eventManager);
}

auto GameLoop::setInputManager(std::unique_ptr<InputManager>&& inputManager) -> void {
    m_inputManager = std::move(inputManager);
}

auto GameLoop::setRenderer(std::unique_ptr<Graphics::Renderer>&& renderer) -> void {
    m_renderer = std::move(renderer);
}
