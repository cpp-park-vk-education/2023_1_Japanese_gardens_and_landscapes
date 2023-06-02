#pragma once

#include "BaseComponent.hpp"
#include "ComponentManager.hpp"

namespace AnimeDefendersEngine {

    namespace {
        constexpr float defaultMaxHealth = 100.f;
    }  // namespace

    class HealthComponent : public BaseComponent<HealthComponent> {
     public:
        HealthComponent(const std::string& entityId, ComponentManager& compManager, float health)
            : BaseComponent<HealthComponent>(entityId, compManager), m_maxHealth(health), m_health(health) {}

        auto addHealth(float health) -> void {
            m_health += health;
            m_health = std::min(m_health, m_maxHealth);
        }

        auto decreaseHealth(float damage) -> void { m_health -= damage; }
        auto getHealth() -> float { return m_health; }
        auto setHealth(float health) -> void { m_health = health; }
        auto setMaxHealth(float maxHealth) -> void { m_maxHealth = maxHealth; }

     private:
        float m_health{defaultMaxHealth};
        float m_maxHealth{defaultMaxHealth};
    };

}  // namespace AnimeDefendersEngine
