#pragma once

#include "ComponentManager.hpp"
#include "Entity.hpp"

#include <memory>
#include <string>
#include <vector>

namespace AnimeDefendersEngine {

    class Scene {
     public:
        void addEntity(std::shared_ptr<Entity>);
        void deleteEntity(std::string entityId);

     private:
        std::vector<std::shared_ptr<Entity>> m_entities;
        std::shared_ptr<IComponentManager> m_components;
        int m_sceneId{};
    };

}  // namespace AnimeDefendersEngine