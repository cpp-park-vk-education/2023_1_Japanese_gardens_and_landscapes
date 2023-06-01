#include "ColliderComponent.hpp"
#include "Entity.hpp"
#include "TransformComponent.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine {

    class Wall : public Entity {
     public:
        Wall(Scene& scene, const std::string& entityId, Math::Vector2f position, Math::Vector2f size);

        auto onCollisionEnter(ColliderComponent& otherCollider) -> void;
        auto onCollisionStay(ColliderComponent& otherCollider) -> void;
        auto onCollisionExit(ColliderComponent& otherCollider) -> void;
        auto update() -> void override;

        TransformComponent transform;
        ColliderComponent collider;

        Math::Vector2f size;
    };

}  // namespace AnimeDefendersEngine