#pragma once

#include "ComponentManager.hpp"

#include <concepts>
#include <memory>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

namespace AnimeDefendersEngine {

    class ComponentManager;
    class Scene;
    class Entity;

}  // namespace AnimeDefendersEngine

namespace AnimeDefendersEngine {

    template <typename T, typename SceneReplacer>
    concept EntityCreator = requires(T x, SceneReplacer scene) {
        { x(std::string{}, scene) } -> std::same_as<std::shared_ptr<Entity>>;
    };

    class Scene {
     public:
        explicit Scene(int id = 0);

        auto addEntity(std::string id, EntityCreator<Scene> auto create) -> void { m_entities[id] = create(id, *this); }
        auto destroyEntity(const std::string& entityId) -> void;

        [[nodiscard]] auto getComponentManager() -> ComponentManager&;

        auto updateScene() -> void;

        auto getSceneId() const noexcept -> int;

     private:
        int m_sceneId{};
        std::unordered_map<std::string, std::shared_ptr<Entity>> m_entities;
        ComponentManager m_components;
        std::vector<std::string> m_entityIdsToDestroy;
    };

}  // namespace AnimeDefendersEngine
