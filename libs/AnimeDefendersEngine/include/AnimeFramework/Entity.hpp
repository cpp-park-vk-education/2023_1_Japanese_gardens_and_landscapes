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
        explicit Entity(const std::string& id, Scene& scene) : m_entityId{id}, m_scene{scene} {}
        auto getId() -> std::string const { return m_entityId; }
        virtual auto update() -> void{};

        auto destroy() -> void;

     protected:
        Scene& m_scene;

     private:
        std::string m_entityId;
    };

}  // namespace AnimeDefendersEngine
