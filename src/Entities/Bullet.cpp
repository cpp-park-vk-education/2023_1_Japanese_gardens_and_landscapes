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

    Bullet::Bullet(Scene& scene, const std::string& entityId, FileSystem::FileSystem& fileSystem, const std::string& textureId,
                   Math::Vector2f position, Math::Vector2f velocity, float mass = defaultBulletMass, float radius = defaultBulletRadius)
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
          sprite(getId(), scene.getComponentManager(), {{position.x, 0, position.y}, 0, 0}, {0}) {
        sprite.setTexture(sprite.getDrawTextureWrapper().loadTexture(fileSystem.getImage(textureId)));
        Logger::defaultLog.printMessage(getId() + " is created!\n");
    }

    auto Bullet::onCollisionEnter(ColliderComponent& otherCollider) -> void {
        Logger::defaultLog.printMessage(getId() + " hited " + otherCollider.getEntityId() + "\n");
        std::cout << "fuck" << std::endl;
        // rigidbody.velocity = rigidbody.velocity * (-1);
        destroy();
    }

    auto Bullet::onCollisionStay(ColliderComponent& otherCollider) -> void {
        std::cout << "fuck" << std::endl;
    }

    auto Bullet::onCollisionExit(ColliderComponent& otherCollider) -> void {}

    auto Bullet::update() -> void {
        // sprite.setTranspose({
        //     {transform.position.x, 0, transform.position.y},
        //     sprite.getTranspose().vecticalViewAngle - 2.f,
        //     sprite.getTranspose().horisontalViewAngle + 2.f
        // });

        sprite.setTranspose({
            {transform.position.x, 0, transform.position.y},
            sprite.getTranspose().vecticalViewAngle,
            sprite.getTranspose().horisontalViewAngle
        });
    };

}  // namespace AnimeDefendersEngine
