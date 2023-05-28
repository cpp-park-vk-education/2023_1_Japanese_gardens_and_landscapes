#pragma once

#include <istream>
#include <memory>
#include <string>
#include <vector>

namespace AnimeDefendersEngine {

    class Scene;
    class Entity;
    class SceneManager;

}  // namespace AnimeDefendersEngine

namespace AnimeDefendersEngine {

    class IEntityCreator {
     public:
        virtual auto create(const std::vector<std::string>& arguments, Scene& scene) -> std::shared_ptr<Entity> = 0;
    };

    class SceneLoader {
     public:
        explicit SceneLoader(std::unique_ptr<std::istream> dataStream, std::unique_ptr<IEntityCreator> creator, SceneManager& sceneManager);
        /*
            while(!dataStream->eof()){
                std::string line;
                std::getline(*dataStream, line);
                std::stringstream properties {line};

                std::vector<std::string> arguments;

                while(!properties.eof()) {
                    std::getline(properties, line);
                    arguments.push_back(line);
                }

                std::size_t id = std::stoull(arguments[0]);

            }

        */

     private:
        auto m_loadScenes() -> void;

     private:
        std::unique_ptr<std::istream> m_dataStream;
        std::unique_ptr<IEntityCreator> m_creator;
        SceneManager& m_sceneManager;
    };

}  // namespace AnimeDefendersEngine
