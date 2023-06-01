#include "HealthBonus.hpp"
#include "Scene.hpp"

#include <iostream>

namespace AnimeDefendersEngine {

    namespace {

        constexpr float defaultBonusRadius = 1.f;

    }  // namespace

    HealthBonus::HealthBonus(Scene& scene, const std::string& entityId, Math::Vector2f position, float radius = defaultBonusRadius)
        : Entity(entityId, scene),
          radius(radius),
          transform(getId(), scene.getComponentManager(), position),
          collider(
              getId(), scene.getComponentManager(), radius, false,
              [this](ColliderComponent& otherCollider) { this->onCollisionEnter(otherCollider); },
              [this](ColliderComponent& otherCollider) { this->onCollisionStay(otherCollider); },
              [this](ColliderComponent& otherCollider) { this->onCollisionExit(otherCollider); }, transform) {
        std::cout << getId() << " is created!\n";
    }

    auto HealthBonus::onCollisionEnter(ColliderComponent& otherCollider) -> void {
        if (otherCollider.getEntityId() == "Player") {
            // do heal
            destroy();
        }
    }

    auto HealthBonus::onCollisionStay(ColliderComponent& otherCollider) -> void {}

    auto HealthBonus::onCollisionExit(ColliderComponent& otherCollider) -> void {}

    auto HealthBonus::update() -> void {
        std::cout << transform.position;
    }

}  // namespace AnimeDefendersEngine
