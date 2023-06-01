#include "AnimeFramework.hpp"

namespace AnimeDefendersEngine {

    AnimeFramework::AnimeFramework()
        : m_sceneManager{},
          m_gameLoop{std::make_unique<SystemManager>(),
                     std::make_unique<Graphics::Renderer>(std::make_unique<Graphics::Window>(1280, 1280, "Gaaaaaay")),
                     std::make_unique<EventManager>(), m_sceneManager} {}

    auto AnimeFramework::run() -> void {
        auto readStream = std::make_unique<std::ifstream>("GameFiles/entities.txt");
        auto entityCreator = std::make_unique<BaseCreator>();

        SceneLoader loadScenes{std::move(readStream), std::move(entityCreator), m_sceneManager};
        m_sceneManager.setActiveScene(0);

        m_gameLoop.run();
    }

}  // namespace AnimeDefendersEngine
