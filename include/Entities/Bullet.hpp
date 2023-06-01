#include "ColliderComponent.hpp"
#include "Entity.hpp"
#include "RigidBodyComponent.hpp"
#include "Sprite.hpp"
#include "TransformComponent.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine {

    class Bullet : public Entity {
     public:
        Bullet(Scene& scene, const FileSystem::FileSystem& fileSystem, const std::string& entityId, Math::Vector2f position,
               Math::Vector2f velocity, float mass, float radius);

        auto onCollisionEnter(ColliderComponent& otherCollider) -> void;
        auto onCollisionStay(ColliderComponent& otherCollider) -> void;
        auto onCollisionExit(ColliderComponent& otherCollider) -> void;
        auto update() -> void override;

        TransformComponent transform;
        RigidBodyComponent rigidbody;
        ColliderComponent collider;
        Graphics::Sprite sprite;

        float mass{};
        float radius{};
    };

}  // namespace AnimeDefendersEngine
