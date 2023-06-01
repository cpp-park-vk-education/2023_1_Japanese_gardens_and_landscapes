#include "Player.hpp"
#include "Logger.hpp"

#include <iostream>

namespace AnimeDefendersEngine {

    namespace {

        constexpr float defaultPlayerRadius = 1.f;
        constexpr float defaultPlayerMass = 3.f;

    }  // namespace

    Player::Player(Scene& scene, FileSystem::FileSystem& fileSystem, const std::string& entityId, Math::Vector2f position,
                   Math::Vector2f velocity, float mass = defaultPlayerMass, float radius = defaultPlayerRadius, float health = 100.f)
        : Entity(entityId, scene),
          m_health(getId(), scene.getComponentManager(), health),
          m_transform(getId(), scene.getComponentManager(), position),
          m_rigidbody(getId(), scene.getComponentManager(), mass, velocity),
          m_collider(
              getId(), scene.getComponentManager(), radius, false,
              [this](ColliderComponent& otherCollider) {
                  this->onCollisionEnter(otherCollider);
    },
              [this](ColliderComponent& otherCollider) { this->onCollisionStay(otherCollider); },
              [this](ColliderComponent& otherCollider) { this->onCollisionExit(otherCollider); }, m_transform, &m_rigidbody),
          m_sprite(getId(), scene.getComponentManager(), {{position.x, 50, position.y}, 0, 0},
                   m_sprite.getDrawTextureWrapper().loadTexture(fileSystem.getImage("Bullet.png"))) {
        Logger::defaultLog.printMessage(getId() + " is created!\n");
    }

    auto Player::onCollisionEnter(ColliderComponent& otherCollider) -> void {
        Logger::defaultLog.printMessage(getId() + " hited " + otherCollider.getEntityId() + "\n");
        // rigidbody.velocity = rigidbody.velocity * (-1);
        destroy();
    }

    auto Player::onCollisionStay(ColliderComponent& otherCollider) -> void {}

    auto Player::onCollisionExit(ColliderComponent& otherCollider) -> void {}

    auto Player::update() -> void{};

}  // namespace AnimeDefendersEngine
