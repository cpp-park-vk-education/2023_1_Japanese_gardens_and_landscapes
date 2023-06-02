#include "DamageZone.hpp"
#include "FileSystem.hpp"
#include "Logger.hpp"
#include "Scene.hpp"

#include <iostream>

namespace AnimeDefendersEngine {

    namespace {

        const Math::Vector2f defaultZoneSize(5.f, 5.f);

    }  // namespace

    DamageZone::DamageZone(Scene& scene, const std::string& entityId, FileSystem::FileSystem& fileSystem, std::string textureId,
                           Math::Vector2f position, Math::Vector2f size = defaultZoneSize)
        : Entity(entityId, scene),
          radius(radius),
          transform(getId(), scene.getComponentManager(), position),
          sprite(getId(), scene.getComponentManager(),
                 {
                     {position.x, -5, position.y},
                     90, 0
    },
                 {0}) {
        sprite.setTexture(sprite.getDrawTextureWrapper().loadTexture(fileSystem.getImage(textureId)));

        Logger::defaultLog.printMessage(getId() + " is created!\n");
    }

    auto DamageZone::update() -> void {
        // AnimeDefendersEngine::Logger::defaultLog.printMessage("rotating");
        // sprite.setTranspose({
        //     {sprite.getTranspose().posCoords.x, sprite.getTranspose().posCoords.y, sprite.getTranspose().posCoords.z},
        //     sprite.getTranspose().vecticalViewAngle + 0.1f,
        //     sprite.getTranspose().horisontalViewAngle
        // });
    }

}  // namespace AnimeDefendersEngine
