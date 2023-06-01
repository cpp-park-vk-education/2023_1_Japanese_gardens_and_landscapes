#pragma once

#include "ColliderComponent.hpp"
#include "Entity.hpp"
#include "FileSystem.hpp"
#include "HealthComponent.hpp"
#include "InputComponent.hpp"
#include "RigidBodyComponent.hpp"
#include "Scene.hpp"
#include "Sprite.hpp"
#include "TransformComponent.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine {

    class Player : public Entity {
     public:
        Player(Scene& scene, FileSystem::FileSystem& fileSystem, InputManager& inputManager, const std::string& entityId,
               Math::Vector2f position, Math::Vector2f velocity, float mass, float radius, float health);

        auto onCollisionEnter(ColliderComponent& otherCollider) -> void;
        auto onCollisionStay(ColliderComponent& otherCollider) -> void;
        auto onCollisionExit(ColliderComponent& otherCollider) -> void;
        auto update() -> void override;

        TransformComponent m_transform;
        RigidBodyComponent m_rigidbody;
        ColliderComponent m_collider;
        Graphics::Sprite m_sprite;
        HealthComponent m_health;
        InputComponent m_inputComponent;
    };

}  // namespace AnimeDefendersEngine
