#include "Wall.hpp"
#include "Logger.hpp"
#include "Scene.hpp"

#include <iostream>

namespace AnimeDefendersEngine {

    namespace {

        const Math::Vector2f defaultWallSize(5, 1);

    }  // namespace

    Wall::Wall(Scene& scene, const std::string& entityId, FileSystem::FileSystem& fileSystem, Math::Vector2f position,
               Math::Vector2f size = defaultWallSize)
        : Entity(entityId, scene),
          size(size),
          transform(getId(), scene.getComponentManager(), position),
          collider(
              getId(), scene.getComponentManager(), size, false,
              [this](ColliderComponent& otherCollider) {
                  this->onCollisionEnter(otherCollider);
    },
              [this](ColliderComponent& otherCollider) { this->onCollisionStay(otherCollider); },
              [this](ColliderComponent& otherCollider) { this->onCollisionExit(otherCollider); }, transform),
          sprite(getId(), scene.getComponentManager(), {{position.x, 50, position.y}, 0, 0}, {0}) {
        sprite.setTexture(sprite.getDrawTextureWrapper().loadTexture(fileSystem.getImage("Wall.png")));
        Logger::defaultLog.printMessage(getId() + " is created!\n");
    }

    auto Wall::onCollisionEnter(ColliderComponent& otherCollider) -> void {}

    auto Wall::onCollisionStay(ColliderComponent& otherCollider) -> void {}

    auto Wall::onCollisionExit(ColliderComponent& otherCollider) -> void {}

    auto Wall::update() -> void {
        // AnimeDefendersEngine::Logger::defaultLog.printMessage("rotating");
        sprite.setTranspose(
            {sprite.getTranspose().posCoords, sprite.getTranspose().horisontalViewAngle + 1, sprite.getTranspose().vecticalViewAngle});
    }

}  // namespace AnimeDefendersEngine
