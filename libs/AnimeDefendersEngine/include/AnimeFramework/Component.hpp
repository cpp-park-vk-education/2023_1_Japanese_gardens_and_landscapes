#pragma once

#include "ComponentManager.hpp"

#include <iostream>
#include <memory>
#include <typeindex>

namespace AnimeDefendersEngine {

    class ComponentManager;

    template <typename T>
    class BaseComponent;

}  // namespace AnimeDefendersEngine

namespace AnimeDefendersEngine {

    class Component {};

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
        explicit BaseComponent(ComponentManager& compManager) : m_compManager{compManager} { compManager.addComponent<T>(this); }
        BaseComponent(const BaseComponent& component) : BaseComponent{component.m_compManager} {}

        virtual ~BaseComponent() { m_compManager.deleteComponent<T>(this); }

     private:
        ComponentManager& m_compManager;
    };

}  // namespace AnimeDefendersEngine
