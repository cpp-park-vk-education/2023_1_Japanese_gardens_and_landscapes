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
    concept EntityCreator = requires(const T& x, SceneReplacer& scene) {
        { x(std::string{}, scene) } -> std::same_as<std::shared_ptr<Entity>>;
    };

    class Scene {
     public:
        using IdType = std::size_t;

     public:
        explicit Scene(std::size_t sceneId);

        auto addEntity(const std::string& info, const EntityCreator<Scene> auto& create) -> void {
            auto entity = create(info, *this);

            m_entities[entity->getId()] = entity;
        }
        auto addEntity(std::shared_ptr<Entity> entity) -> void;

        auto destroyEntity(const std::string& entityId) -> void;

        [[nodiscard]] auto getComponentManager() -> ComponentManager&;

        auto updateScene() -> void;

        [[nodiscard]] auto getSceneId() const noexcept -> IdType;

     private:
        IdType m_sceneId{};
        std::unordered_map<std::string, std::shared_ptr<Entity>> m_entities;
        ComponentManager m_componentManager;
        std::vector<std::string> m_entityIdsToDestroy;
    };

}  // namespace AnimeDefendersEngine
