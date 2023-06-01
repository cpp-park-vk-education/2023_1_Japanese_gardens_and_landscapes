#include "Bullet.hpp"
#include "FileSystem.hpp"
#include "Logger.hpp"
#include "Scene.hpp"

#include <iostream>

namespace AnimeDefendersEngine {

    namespace {

        constexpr float defaultBulletRadius = 1.f;
        constexpr float defaultBulletMass = 1.f;

    }  // namespace

    Bullet::Bullet(Scene& scene, FileSystem::FileSystem& fileSystem, const std::string& entityId, Math::Vector2f position,
                   Math::Vector2f velocity, float mass = defaultBulletMass, float radius = defaultBulletRadius)
        : Entity(entityId, scene),
          mass(mass),
          radius(radius),
          transform(getId(), scene.getComponentManager(), position),
          rigidbody(getId(), scene.getComponentManager(), mass, velocity),
          collider(
              getId(), scene.getComponentManager(), radius, false,
              [this](ColliderComponent& otherCollider) {
                  this->onCollisionEnter(otherCollider);
    },
              [this](ColliderComponent& otherCollider) { this->onCollisionStay(otherCollider); },
              [this](ColliderComponent& otherCollider) { this->onCollisionExit(otherCollider); }, transform, &rigidbody),
          sprite(getId(), scene.getComponentManager(), {{position.x, 50, position.y}, 0, 0},
                 sprite.getDrawTextureWrapper().loadTexture(fileSystem.getImage("Bullet.png"))) {
        Logger::defaultLog.printMessage(getId() + " is created!\n");
    }

    auto Bullet::onCollisionEnter(ColliderComponent& otherCollider) -> void {
        Logger::defaultLog.printMessage(getId() + " hited " + otherCollider.getEntityId() + "\n");
        // rigidbody.velocity = rigidbody.velocity * (-1);
        destroy();
    }

    auto Bullet::onCollisionStay(ColliderComponent& otherCollider) -> void {}

    auto Bullet::onCollisionExit(ColliderComponent& otherCollider) -> void {}

    auto Bullet::update() -> void{};

}  // namespace AnimeDefendersEngine
