#pragma once

#include "Component.hpp"
#include <string>
#include <vector>

namespace AnimeDefendersEngine {
enum class ComponentType { Sprite, Camera, UiElement, Audio, Collider2DComponent, RigidBody2DComponent };
class Entity {
 public:
    auto addComponent(Component* component) -> void;
    auto getComponent(ComponentType componentType) -> Component*;

 private:
    std::string m_entityId;
    std::vector<Component*> m_entityComponents;
};
}  // namespace AnimeDefendersEngine
