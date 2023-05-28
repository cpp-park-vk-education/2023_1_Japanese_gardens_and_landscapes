#include "SceneManager.hpp"
#include "Scene.hpp"

namespace AnimeDefendersEngine {

    [[nodiscard]] auto SceneManager::getActiveScene() -> Scene& {
        return *m_scenes.at(m_activeSceneId).get();
    }

    auto SceneManager::setActiveScene(std::size_t sceneId) noexcept -> void {
        m_activeSceneId = sceneId;
    }

    auto SceneManager::addScene(std::unique_ptr<Scene> scene) -> void {
        m_scenes[scene->getSceneId()] = std::move(scene);
    }

    auto SceneManager::getScenes() -> std::unordered_map<int, std::unique_ptr<Scene>>& {
        return m_scenes;
    }

}  // namespace AnimeDefendersEngine
