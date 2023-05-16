#pragma once

#include "MemoryMaster.hpp"

#include <ranges>
#include <typeindex>
#include <unordered_map>
#include <vector>

namespace AnimeDefendersEngine {
    class Component;

    class IComponentManager {
     public:
        virtual void addComponent(std::type_index typeId, Component* component) = 0;
        virtual void deleteComponent(std::type_index typeId, Component* compoment) = 0;

        /**
            @brief
            Returns std::vector of pointers to components.
            It is not guaranteed that all components have type which is passed using typeid(T), because type_index can be the same for
           different type.

            @warning
            Requires downcast type check. Consider using getComponentsSecured<T>() instead.
        */

        virtual auto getComponents(std::type_index typeId) -> std::vector<Component*> = 0;

        template <std::derived_from<Component> T>
        auto getComponentsSecured() {
            auto helper = [](Component* comp) { return (dynamic_cast<T>(comp) != nullptr); };
            return this->getComponents(typeid(T)) | std::ranges::filter(helper);
        }
    };

    class ComponentManager : public IComponentManager {
     public:
        void addComponent(std::type_index typeId, Component* component) override;
        void deleteComponent(std::type_index typeId, Component* compoment) override;
        auto getComponents(std::type_index typeId) -> std::vector<Component*> override;

     private:
        std::unordered_map<std::type_index, std::vector<Component*>> m_components;
    };
}  // namespace AnimeDefendersEngine
