// static_assert(false, "Need to include EventManager properly");

#include "GameLoop.hpp"
#include "EventManager.hpp"
#include "InputManager.hpp"
#include "Renderer.hpp"
#include "SceneManager.hpp"
#include "SystemManager.hpp"

#include <chrono>

using namespace AnimeDefendersEngine;

GameLoop::GameLoop(std::unique_ptr<ISystemManager>&& systemManager, std::unique_ptr<IEventManager>&& eventManager,
                   std::unique_ptr<InputManager>&& inputManager, std::unique_ptr<Graphics::Renderer>&& renderer, SceneManager& sceneManager,
                   ComponentManager* componentManager, float fixedDeltaTime, float maxDeltaTime)
    : m_sceneManager(sceneManager), m_fixedDeltaTime(fixedDeltaTime), m_maxDeltaTime(maxDeltaTime), m_isRunning(true) {
    setSystemManager(std::move(systemManager));
    setEventManager(std::move(eventManager));
    setInputManager(std::move(inputManager));
    setRenderer(std::move(renderer));
}

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

namespace {

    class Timer {
     public:
        Timer() { reset(); }
        auto reset() -> void { m_startTime = std::chrono::high_resolution_clock::now(); }
        auto getCurrentTimeInMilliseconds() -> float {
            return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - m_startTime).count();
        };

     private:
        std::chrono::time_point<std::chrono::high_resolution_clock> m_startTime;
    };

}  // namespace

auto GameLoop::run() -> void {
    Timer timer;
    float timeElapsedSinceLastUpdate = timer.getCurrentTimeInMilliseconds();
    float accumulator{};
    while (m_isRunning) {
        float newTime = timer.getCurrentTimeInMilliseconds();
        float deltaTime = newTime - timeElapsedSinceLastUpdate;
        timeElapsedSinceLastUpdate = newTime;

        accumulator += deltaTime;
        if (accumulator > m_maxDeltaTime) {
            accumulator = m_maxDeltaTime;
        }
        while (accumulator >= m_fixedDeltaTime) {
            // m_inputManager->processInput();
            m_systemManager->updateSystems(m_sceneManager, m_fixedDeltaTime);
            accumulator -= m_fixedDeltaTime;
        }
        m_renderer->renderObjects(*m_sceneManager.getActiveScene());
    }
}
