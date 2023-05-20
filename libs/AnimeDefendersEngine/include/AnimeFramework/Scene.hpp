#pragma once

#include <concepts>
#include <memory>
#include <queue>
#include <string>
#include <vector>

namespace AnimeDefendersEngine {

    class ComponentManager;
    class Scene;
    class Entity;

}  // namespace AnimeDefendersEngine

namespace AnimeDefendersEngine {

    template <typename T>
    concept EntityCreator = requires(T x) {
        { x(std::string{}, Scene{10}) } -> std::same_as<std::shared_ptr<Entity>>;
    };

    class Scene {
     public:
        explicit Scene(int id) : m_sceneId{id} {}

        auto addEntity(std::string id, EntityCreator auto create) -> void { m_entities[id] = create(id, *this); };
        auto destroyEntity(const std::string& entityId) -> void { m_entityIdsToDestroy.push_back(entityId); }

        [[nodiscard]] auto getComponentManager() -> ComponentManager& { return m_components; };

        auto updateScene() -> void {
            while (!m_entityIdsToDestroy.empty()) {
                const auto& id = m_entityIdsToDestroy.back();
                m_entities.erase(id);
                m_entityIdsToDestroy.pop_back();
            }
        }

        auto getSceneId() const noexcept -> int { return m_sceneId; }

     private:
        int m_sceneId{};
        std::unordered_map<std::string, std::shared_ptr<Entity>> m_entities;
        ComponentManager m_components;
        std::vector<std::string> m_entityIdsToDestroy;
    };

}  // namespace AnimeDefendersEngine
