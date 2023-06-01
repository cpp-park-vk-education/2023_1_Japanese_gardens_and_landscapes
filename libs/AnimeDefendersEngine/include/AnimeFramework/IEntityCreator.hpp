#pragma once

#include <memory>
#include <string>
#include <vector>

namespace AnimeDefendersEngine {

    class Scene;
    class Entity;

}  // namespace AnimeDefendersEngine

namespace AnimeDefendersEngine {

    class IEntityCreator {
     public:
        virtual auto create(const std::vector<std::string>& arguments, Scene& scene) -> std::shared_ptr<Entity> = 0;
        virtual ~IEntityCreator() = default;
    };

}  // namespace AnimeDefendersEngine
