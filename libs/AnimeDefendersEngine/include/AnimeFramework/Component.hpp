#pragma once

#include "ComponentManager.hpp"

#include <typeindex>

namespace AnimeDefendersEngine {

    /*
    enum class ComponentType {
        Sprite,
        Camera,
        UiElement,
        Audio,
        Collider2DComponent,
        RigidBody2DComponent
    };
    */

    class Component {
     public:
        Component(std::type_index typeId, ComponentManager& compManager) : m_typeId{typeId}, m_compManager{compManager} {
            m_compManager.addComponent(m_typeId, this);
        }

        virtual ~Component() {
            if (is_ComponentManagerExists) {
                m_compManager.deleteComponent(m_typeId, this);
            }
        }

     private:
        friend class ComponentManager;
        void m_componentManagerDestroyed() { is_ComponentManagerExists = false; }

     private:
        bool is_ComponentManagerExists{true};
        std::type_index m_typeId;
        ComponentManager& m_compManager;
    };

}  // namespace AnimeDefendersEngine
