#include "Monster.hpp"
#include "Logger.hpp"

#include <iostream>

namespace AnimeDefendersEngine {

    namespace {

        constexpr float defaultMonsterRadius = 1.f;
        constexpr float defaultMonsterMass = 3.f;
        constexpr float defaultMonsterHealth = 10.f;

    }  // namespace

    Monster::Monster(Scene& scene, FileSystem::FileSystem& fileSystem, const std::string& entityId,
                   Math::Vector2f position, Math::Vector2f velocity, float mass = defaultMonsterMass, float radius = defaultMonsterRadius,
                   float health = defaultMonsterHealth)
        : Entity(entityId, scene),
          m_health(getId(), scene.getComponentManager(), health),
          m_transform(getId(), scene.getComponentManager(), position),
          m_rigidbody(getId(), scene.getComponentManager(), mass, velocity),
          m_collider(
              getId(), scene.getComponentManager(), radius, false,
              [this](ColliderComponent& otherCollider) { this->onCollisionEnter(otherCollider); },
              [this](ColliderComponent& otherCollider) { this->onCollisionStay(otherCollider); },
              [this](ColliderComponent& otherCollider) { this->onCollisionExit(otherCollider); }, m_transform, &m_rigidbody), 
              m_sprite(getId(), scene.getComponentManager(), {{position.x, 0, position.y}, 0, 0}, {0}) {
            m_sprite.setTexture(m_sprite.getDrawTextureWrapper().loadTexture(fileSystem.getImage("Monster.png")));
        Logger::defaultLog.printMessage(getId() + " is created!\n");
    }

    auto Monster::onCollisionEnter(ColliderComponent& otherCollider) -> void {}

    auto Monster::onCollisionStay(ColliderComponent& otherCollider) -> void {}

    auto Monster::onCollisionExit(ColliderComponent& otherCollider) -> void {}

    auto Monster::update() -> void {
    };

}  // namespace AnimeDefendersEngine
