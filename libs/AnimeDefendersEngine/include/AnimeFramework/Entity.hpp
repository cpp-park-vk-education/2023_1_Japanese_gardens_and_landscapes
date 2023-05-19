#pragma once

#include "Component.hpp"

#include <string>
#include <vector>

namespace AnimeDefendersEngine {
    class Scene;
}

namespace AnimeDefendersEngine {

    class Entity {
     public:
        explicit Entity(Scene& scene) : m_scene{scene} {}
        auto getId() -> std::string const { return m_entityId; }
        virtual auto update() -> void = 0;

        auto destroy() -> void { m_scene.destroyEntity(m_entityId); }

     private:
        std::string m_entityId;
        Scene& m_scene;
    };

}  // namespace AnimeDefendersEngine
