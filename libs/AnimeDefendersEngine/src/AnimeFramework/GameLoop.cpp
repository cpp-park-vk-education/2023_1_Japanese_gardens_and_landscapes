#include "GameLoop.hpp"
#include "EventManager.hpp"
#include "InputManager.hpp"
#include "Renderer.hpp"
#include "SceneManager.hpp"
#include "SystemManager.hpp"

#include <chrono>

namespace AnimeDefendersEngine {

    namespace {

        constexpr float defaultFixedUpdateFrequency = 60.f;
        constexpr float defaultMinUpdateFrequency = 25.f;

        using Clock = std::chrono::high_resolution_clock;

        class Timer {
         public:
            Timer() { reset(); }
            auto reset() -> void { m_startTime = Clock::now(); }
            auto getCurrentTimeInMilliseconds() const -> float {
                return std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now() - m_startTime).count();
            };

         private:
            std::chrono::time_point<std::chrono::high_resolution_clock> m_startTime;
        };

        [[nodiscard]] auto getGameEndEventName() noexcept {
            return "GameEnd";
        }

    }  // namespace

    GameLoop::GameLoop(std::unique_ptr<ISystemManager> systemManager, std::unique_ptr<Graphics::Renderer> renderer,
                       std::unique_ptr<EventManager> eventManager, SceneManager& sceneManager, float fixedDeltaTime, float maxDeltaTime)
        : m_sceneManager(sceneManager),
          m_systemManager(std::move(systemManager)),
          m_renderer(std::move(renderer)),
          m_eventManager(std::move(eventManager)),
          m_fixedDeltaTime(fixedDeltaTime),
          m_maxDeltaTime(maxDeltaTime),
          m_isRunning(true) {}

    GameLoop::GameLoop(std::unique_ptr<ISystemManager> systemManager, std::unique_ptr<Graphics::Renderer> renderer,
                       std::unique_ptr<EventManager> eventManager, SceneManager& sceneManager)
        : GameLoop(std::move(systemManager), std::move(renderer), , std::move(eventManager), sceneManager,
                   1.f / defaultFixedUpdateFrequency, 1.f / defaultMinUpdateFrequency) {}

    auto GameLoop::run() -> void {
        Timer timer{};
        float timeElapsedSinceLastUpdate = 0.f;
        float accumulator{0};
        while (m_isRunning) {
            const auto newTime = timer.getCurrentTimeInMilliseconds();
            const auto deltaTime = newTime - timeElapsedSinceLastUpdate;
            timeElapsedSinceLastUpdate = newTime;

            accumulator += deltaTime;
            if (accumulator > m_maxDeltaTime) {
                accumulator = m_maxDeltaTime;
            }
            while (accumulator >= m_fixedDeltaTime) {
                m_systemManager->updateSystems(m_sceneManager, m_fixedDeltaTime);
                accumulator -= m_fixedDeltaTime;

                if (m_eventManager.hasEvent(getGameEndEventName())) {
                    m_isRunning = false;
                    break;
                }

                m_eventManager.update();
            }
            m_renderer->renderObjects(m_sceneManager.getActiveScene());
        }
    }

}  // namespace AnimeDefendersEngine
