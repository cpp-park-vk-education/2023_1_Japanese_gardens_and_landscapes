#pragma once

#include "Component.hpp"
#include "MemoryMaster.hpp"

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

namespace AnimeDefendersEngine {

    class Component;

}  // namespace AnimeDefendersEngine

namespace AnimeDefendersEngine {

    class ComponentManager {
     public:
        using ComponentsContainer = std::unordered_map<std::string, Component*>;

     public:
        ComponentManager() = default;

        ComponentManager(const ComponentManager&) = delete;
        ComponentManager(ComponentManager&&) = delete;

        auto operator=(const ComponentManager&) -> ComponentManager& = delete;
        auto operator=(ComponentManager&&) -> ComponentManager& = delete;

        /**
         * @brief
         * Returns std::unordered_map with values - pointers to components of certain type and keys - entityIds.
         */
        template <std::derived_from<Component> T>
        [[nodiscard]] auto getComponents() -> ComponentsContainer& {
            static std::unordered_map<ComponentManager*, ComponentsContainer> components;
            return components[this];
        }

        template <std::derived_from<Component> T>
        auto addComponent(Component* component) -> void {
            auto& components = getComponents<T>();

            components[component->getEntityId()] = component;
        }

        template <std::derived_from<Component> T>
        auto deleteComponent(Component* component) -> void {
            auto& components = getComponents<T>();

            if (components.contains(component->getEntityId()) && components[component->getEntityId()] == component) {
                components.erase(component->getEntityId());
            }
        }
    };

}  // namespace AnimeDefendersEngine
