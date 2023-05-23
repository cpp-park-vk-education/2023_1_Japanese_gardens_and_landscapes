#include "SceneManager.hpp"
#include "Scene.hpp"

using namespace AnimeDefendersEngine;

[[nodiscard]] auto SceneManager::getActiveScene() -> Scene& {
    return *m_scenes.at(m_activeSceneId).get();
}

auto SceneManager::setActiveScene(int sceneId) noexcept -> void {
    m_activeSceneId = sceneId;
}

auto SceneManager::addScene(std::unique_ptr<Scene> scene) -> void {
    m_scenes[scene->getSceneId()] = std::move(scene);
}
