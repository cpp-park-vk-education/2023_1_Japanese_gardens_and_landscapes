#include "ColliderComponent.hpp"
#include "Entity.hpp"
#include "FileSystem.hpp"
#include "RigidBodyComponent.hpp"
#include "Sprite.hpp"
#include "TransformComponent.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine {

    class Bullet : public Entity {
     public:
        Bullet(Scene& scene, const std::string& entityId, FileSystem::FileSystem& fileSystem, const std::string& textureId,
               Math::Vector2f position, Math::Vector2f velocity, TransformComponent* transform, float mass, float radius);

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
