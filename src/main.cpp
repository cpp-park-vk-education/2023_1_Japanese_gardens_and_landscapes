#include <iostream>
#include "AnimeFramework.hpp"
#include "Bullet.hpp"
#include "Camera.hpp"
#include "FileSystem.hpp"
#include "Logger.hpp"
#include "Scene.hpp"
#include "Vector2.hpp"
#include "Wall.hpp"

#include <memory>

// namespace AnimeDefendersEngine {

// auto createWall(std::vector<std::string>& arguments, Scene& scene, FileSystem::FileSystem& fileSystem) -> std::shared_ptr<Entity> {
//     std::string entityId = arguments.at(2);
//     Math::Vector2f position(std::stof(arguments.at(3)), std::stof(arguments.at(4)));
//     Math::Vector2f size(std::stof(arguments.at(5)), std::stof(arguments.at(6)));
//     return std::make_shared<Wall>(scene, entityId, fileSystem, position, size);
// }

//     class Creator : public BaseCreator {
//      public:
//         auto create(const std::vector<std::string>& arguments, Scene& scene) -> std::shared_ptr<Entity> override {
//             std::string entityId = arguments.at(2);
//             Math::Vector2f position(std::stof(arguments.at(3)), std::stof(arguments.at(4)));
//             Math::Vector2f size(std::stof(arguments.at(5)), std::stof(arguments.at(6)));
//             return std::make_shared<Wall>(scene, entityId, fileSystem, position, size);
//         };
//     };

// }  // namespace AnimeDefendersEngine

//     auto createHealthBonus(std::vector<std::string>& arguments, Scene& scene, FileSystem::FileSystem& fileSystem)
//         -> std::shared_ptr<Entity> {
//         std::string entityId = arguments.at(2);
//         Math::Vector2f position(std::stof(arguments.at(3)), std::stof(arguments.at(4)));
//         Math::Vector2f size(std::stof(arguments.at(5)), std::stof(arguments.at(6)));
//         return std::make_shared<Bullet>(scene, entityId, fileSystem, position, size);
//     }

// }  // namespace AnimeDefendersEngine

class Game : public AnimeDefendersEngine::AnimeFramework {
 public:
    auto run() -> void {
        // auto readStream = std::make_unique<std::ifstream>("GameFiles/entities.txt");
        // auto entityCreator = std::make_unique<AnimeDefendersEngine::BaseCreator>();

        // AnimeDefendersEngine::SceneLoader loadScenes{std::move(readStream), std::move(entityCreator), m_sceneManager};
        auto scene = std::make_unique<AnimeDefendersEngine::Scene>(0);
        m_sceneManager.addScene(std::move(scene));
        m_sceneManager.setActiveScene(0);
        using AnimeDefendersEngine::Math::Vector2f;
        AnimeDefendersEngine::FileSystem::FileSystem fileSystem("GameFiles/resourceLocations.txt");
        m_sceneManager.getActiveScene().addEntity(std::make_shared<AnimeDefendersEngine::Bullet>(
            m_sceneManager.getActiveScene(), fileSystem, "dsds", Vector2f(0, 0), Vector2f(0, 0), 1, 1));
        m_gameLoop.run();
    }
};

auto subMain() -> int {
    Game game;
    game.run();
    return 0;
}

auto main() -> int {
    return subMain();
}
