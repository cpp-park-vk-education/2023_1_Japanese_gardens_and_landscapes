#include "DamageZone.hpp"
#include "Scene.hpp"

#include <iostream>

namespace AnimeDefendersEngine {

    namespace {

        const Math::Vector2f defaultZoneSize(5.f, 5.f);

    }  // namespace

    DamageZone::DamageZone(Scene& scene, const std::string& entityId, Math::Vector2f position, Math::Vector2f size = defaultZoneSize)
        : Entity(entityId, scene),
          radius(radius),
          transform(getId(), scene.getComponentManager(), position),
          collider(
              getId(), scene.getComponentManager(), size, true,
              [this](ColliderComponent& otherCollider) { this->onCollisionEnter(otherCollider); },
              [this](ColliderComponent& otherCollider) { this->onCollisionStay(otherCollider); },
              [this](ColliderComponent& otherCollider) { this->onCollisionExit(otherCollider); }, transform) {
        std::cout << getId() << " is created!\n";
    }

    auto DamageZone::onCollisionEnter(ColliderComponent& otherCollider) -> void {}

    auto DamageZone::onCollisionStay(ColliderComponent& otherCollider) -> void {
        // do damage
    }

    auto DamageZone::onCollisionExit(ColliderComponent& otherCollider) -> void {}

    auto DamageZone::update() -> void {
        std::cout << transform.position;
    }

}  // namespace AnimeDefendersEngine
