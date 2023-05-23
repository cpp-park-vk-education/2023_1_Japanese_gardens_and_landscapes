#pragma once

#include "Component.hpp"
#include "MemoryMaster.hpp"

#include <iostream>
#include <set>
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
        explicit ComponentManager(std::size_t id) : m_id{id} {}

        /**
         * @brief
         * Returns std::unordered_map with values - pointers to components of certain type and keys - entityIds.
         */
        template <std::derived_from<Component> T>
        [[nodiscard]] auto getComponents() -> ComponentsContainer& {
            static std::unordered_map<std::size_t, ComponentsContainer> components;
            return components[m_id];
        }

        template <std::derived_from<Component> T>
        auto addComponent(Component* component) -> void {
            auto& components = getComponents<T>();

            components[component->getEntityId()] = component;
        }

        template <std::derived_from<Component> T>
        auto deleteComponent(Component* component) -> void {
            auto& components = getComponents<T>();
            components.erase(component->getEntityId());
        }

     private:
        std::size_t m_id{};
    };

}  // namespace AnimeDefendersEngine
