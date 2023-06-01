#include "Wall.hpp"
#include "Scene.hpp"

#include <iostream>

namespace AnimeDefendersEngine {

    namespace {

        const Math::Vector2f defaultWallSize(5, 1);

    }  // namespace

    Wall::Wall(Scene& scene, const std::string& entityId, Math::Vector2f position, Math::Vector2f size = defaultWallSize)
        : Entity(entityId, scene),
          size(size),
          transform(getId(), scene.getComponentManager(), position),
          collider(
              getId(), scene.getComponentManager(), size, false,
              [this](ColliderComponent& otherCollider) { this->onCollisionEnter(otherCollider); },
              [this](ColliderComponent& otherCollider) { this->onCollisionStay(otherCollider); },
              [this](ColliderComponent& otherCollider) { this->onCollisionExit(otherCollider); }, transform) {
        std::cout << getId() << " is created!\n";
    }

    auto Wall::onCollisionEnter(ColliderComponent& otherCollider) -> void {}

    auto Wall::onCollisionStay(ColliderComponent& otherCollider) -> void {}

    auto Wall::onCollisionExit(ColliderComponent& otherCollider) -> void {}

    auto Wall::update() -> void {}

}  // namespace AnimeDefendersEngine
