#pragma once

#include "Component.hpp"
#include "ComponentManager.hpp"

namespace AnimeDefendersEngine {

    class ComponentManager;
    class Component;

}  // namespace AnimeDefendersEngine

namespace AnimeDefendersEngine {

    /**
     * @example
     * class Sample : public AnimeDefendersEngine::BaseComponent<Sample> {
     *  public:
     *      Sample(AnimeDefendersEngine::ComponentManager& compManager) : AnimeDefendersEngine::BaseComponent<Sample>(compManager) {}
     * };
     */
    template <typename T>
    class BaseComponent : public Component {
     public:
        explicit BaseComponent(const std::string& entityId, ComponentManager& compManager)
            : Component{entityId}, m_compManager{compManager} {
            compManager.addComponent<T>(this);
        }
        BaseComponent(const BaseComponent& component) : BaseComponent{component.getEntityId(), component.m_compManager} {}

        virtual ~BaseComponent() { m_compManager.deleteComponent<T>(this); }

     private:
        ComponentManager& m_compManager;
    };

}  // namespace AnimeDefendersEngine
