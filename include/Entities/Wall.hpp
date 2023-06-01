#include "ColliderComponent.hpp"
#include "Entity.hpp"
#include "FileSystem.hpp"
#include "Sprite.hpp"
#include "TransformComponent.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine {

    class Wall : public Entity {
     public:
        Wall(Scene& scene, const std::string& entityId, FileSystem::FileSystem& fileSystem, Math::Vector2f position, Math::Vector2f size);

        auto onCollisionEnter(ColliderComponent& otherCollider) -> void;
        auto onCollisionStay(ColliderComponent& otherCollider) -> void;
        auto onCollisionExit(ColliderComponent& otherCollider) -> void;
        auto update() -> void override;

        TransformComponent transform;
        ColliderComponent collider;
        Graphics::Sprite sprite;

        Math::Vector2f size;
    };

}  // namespace AnimeDefendersEngine