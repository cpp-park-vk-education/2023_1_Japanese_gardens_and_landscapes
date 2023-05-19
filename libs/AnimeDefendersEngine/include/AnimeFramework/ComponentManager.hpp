#pragma once

#include "MemoryMaster.hpp"

#include <unordered_map>
#include <unordered_set>

namespace AnimeDefendersEngine {

    class Component;

    template <typename T>
    class BaseComponent;

}  // namespace AnimeDefendersEngine

namespace AnimeDefendersEngine {

    class ComponentManager {
     public:
        ComponentManager() = default;

        ComponentManager(const ComponentManager&) = delete;
        ComponentManager(ComponentManager&&) = delete;

        auto operator=(const ComponentManager&) -> ComponentManager& = delete;
        auto operator=(ComponentManager&&) -> ComponentManager& = delete;

        /**
         * @brief
         * Returns std::unordered_set of pointers to components of certain type.
         */
        template <std::derived_from<Component> T>
        [[nodiscard]] auto getComponents() -> std::unordered_set<Component*>& {
            static std::unordered_map<ComponentManager*, std::unordered_set<Component*>> components;
            return components[this];
        }

        template <std::derived_from<Component> T>
        auto addComponent(Component* component) -> void {
            auto& components = getComponents<T>();

            if (!components.contains(component)) {
                components.emplace(component);
            }
        }

        template <std::derived_from<Component> T>
        auto deleteComponent(Component* component) -> void {
            auto& components = getComponents<T>();

            if (components.contains(component)) {
                components.erase(component);
            }
        }
    };

}  // namespace AnimeDefendersEngine
