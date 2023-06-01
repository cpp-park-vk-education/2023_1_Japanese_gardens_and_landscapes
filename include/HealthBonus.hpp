#include "ColliderComponent.hpp"
#include "Entity.hpp"
#include "RigidBodyComponent.hpp"
#include "TransformComponent.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine {

    class HealthBonus : Entity {
     public:
        HealthBonus(Scene& scene, const std::string& entityId, Math::Vector2f position, float radius);

        auto onCollisionEnter(ColliderComponent& otherCollider) -> void;
        auto onCollisionStay(ColliderComponent& otherCollider) -> void;
        auto onCollisionExit(ColliderComponent& otherCollider) -> void;
        auto update() -> void override;

        TransformComponent transform;
        ColliderComponent collider;

        float radius{};
    };

}  // namespace AnimeDefendersEngine