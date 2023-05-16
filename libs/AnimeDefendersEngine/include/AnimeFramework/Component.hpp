#pragma once

#include "ComponentManager.hpp"

#include <memory>
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
        Component(std::type_index typeId, std::weak_ptr<IComponentManager> compManager) : m_typeId{typeId}, m_compManager{compManager} {
            m_compManager.lock()->addComponent(m_typeId, this);
        }

        virtual ~Component() {
            if (!m_compManager.expired()) {
                m_compManager.lock()->deleteComponent(m_typeId, this);
            }
        }

     private:
     private:
        std::type_index m_typeId;
        std::weak_ptr<IComponentManager> m_compManager;
    };

}  // namespace AnimeDefendersEngine
