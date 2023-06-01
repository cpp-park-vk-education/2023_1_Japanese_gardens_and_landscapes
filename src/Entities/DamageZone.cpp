#include "DamageZone.hpp"
#include "Logger.hpp"
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
        Logger::defaultLog.printMessage(getId() + " is created!\n");
    }

    auto DamageZone::onCollisionEnter(ColliderComponent& otherCollider) -> void {
        Logger::defaultLog.printMessage(otherCollider.getEntityId() + " entered DamageZone\n");
    }

    auto DamageZone::onCollisionStay(ColliderComponent& otherCollider) -> void {}

    auto DamageZone::onCollisionExit(ColliderComponent& otherCollider) -> void {
        Logger::defaultLog.printMessage(otherCollider.getEntityId() + " exited DamageZone\n");
    }

    auto DamageZone::update() -> void {}

}  // namespace AnimeDefendersEngine
