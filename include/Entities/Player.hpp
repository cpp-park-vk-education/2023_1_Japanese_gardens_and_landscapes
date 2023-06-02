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
#include "Camera.hpp"

namespace AnimeDefendersEngine {

    class Player : public Entity {
     public:
        Player(Scene& scene, FileSystem::FileSystem& fileSystem, InputManager& inputManager, const std::string& entityId,
               Math::Vector2f position, Math::Vector2f velocity, float mass, float radius, float health, Math::Transpose transpose);

        auto onCollisionEnter(ColliderComponent& otherCollider) -> void;
        auto onCollisionStay(ColliderComponent& otherCollider) -> void;
        auto onCollisionExit(ColliderComponent& otherCollider) -> void;
        auto update() -> void override;

        TransformComponent m_transform;
        RigidBodyComponent m_rigidbody;
        ColliderComponent m_collider;
        HealthComponent m_health;
        InputComponent m_inputComponent;
        Graphics::Camera m_camera;
    };

}  // namespace AnimeDefendersEngine
