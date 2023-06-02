#include "ColliderComponent.hpp"
#include "Entity.hpp"
#include "FileSystem.hpp"
#include "RigidBodyComponent.hpp"
#include "Sprite.hpp"
#include "TransformComponent.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine {

    class DamageZone : public Entity {
     public:
        DamageZone(Scene& scene, const std::string& entityId, FileSystem::FileSystem& fileSystem, std::string textureId,
                   Math::Vector2f position, Math::Vector2f size);

        auto update() -> void override;

        TransformComponent transform;
        Graphics::Sprite sprite;

        float radius{};
    };

}  // namespace AnimeDefendersEngine