#include <iostream>
#include "AnimeFramework.hpp"
#include "Bullet.hpp"
#include "Camera.hpp"
#include "DamageZone.hpp"
#include "FileSystem.hpp"
#include "InputManager.hpp"
#include "Logger.hpp"
#include "Monster.hpp"
#include "Player.hpp"
#include "Renderer.hpp"
#include "Scene.hpp"
#include "Transpose.hpp"
#include "Vector2.hpp"
#include "Wall.hpp"
#include "Window.hpp"

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
        AnimeDefendersEngine::FileSystem::FileSystem fileSystem{absolutePath("GameFiles/resourceLocations.txt")};
        AnimeDefendersEngine::InputManager inputManager{*m_gameLoop.getEventManager(), m_gameLoop.getRenderer()->getActiveWindowPtr()};
        // std::cout << "Input manager initialized " << std::endl;
        //  m_sceneManager.getActiveScene().addEntity(std::make_shared<AnimeDefendersEngine::Bullet>(
        //      m_sceneManager.getActiveScene(), fileSystem, "dsds", Vector2f(0, 0), Vector2f(0, 0), 1, 1));
        AnimeDefendersEngine::Math::Transpose tp{
            {10, 0, 20},
            45, 45
        };

        AnimeDefendersEngine::Logger::defaultLog.printMessage(" trying to create player!");

        m_sceneManager.getActiveScene().addEntity(std::make_shared<AnimeDefendersEngine::Player>(
            m_sceneManager.getActiveScene(), fileSystem, inputManager, "Player", Vector2f(0, 0), Vector2f(0, 0), 1, 0.1, 1000, tp));

        for (int i = 0; i < 7; i++) {
            m_sceneManager.getActiveScene().addEntity(
                std::make_shared<AnimeDefendersEngine::Wall>(m_sceneManager.getActiveScene(), "Wall100" + std::to_string(i), fileSystem,
                                                             "Wall1", Vector2f(1, -1 + 2 * i), Vector2f(0.5, 0.05)));
        }
        for (int i = 0; i < 7; i++) {
            m_sceneManager.getActiveScene().addEntity(
                std::make_shared<AnimeDefendersEngine::Wall>(m_sceneManager.getActiveScene(), "Wall200" + std::to_string(i), fileSystem,
                                                             "Wall1", Vector2f(-2 * i, -2), Vector2f(0.05, 0.5)));
        }

        for (int i = 3; i < 17; ++i) {
            for (int j = -4; j < 11; ++j) {
                m_sceneManager.getActiveScene().addEntity(std::make_shared<AnimeDefendersEngine::DamageZone>(
                    m_sceneManager.getActiveScene(), "floor" + std::to_string(i) + std::to_string(j), fileSystem, "floor2",
                    Vector2f(10 - 2 * i, 11 - 2 * j), Vector2f(0.1, 0.5)));
            }
        }
        m_sceneManager.getActiveScene().addEntity(
            std::make_shared<AnimeDefendersEngine::Bullet>(m_sceneManager.getActiveScene(), "bullet" + std::to_string(0), fileSystem,
                                                           "Bullet", Vector2f(0, -0.5), Vector2f(0, -0.2f), 0.1, 0.1));

        // m_sceneManager.getActiveScene().addEntity(std::make_shared<AnimeDefendersEngine::Monster>(
        //     m_sceneManager.getActiveScene(), fileSystem, "Monster1", Vector2f(0.f, -1.7f), Vector2f(0, 0), 3, 0.2, 10));

        // m_sceneManager.getActiveScene().addEntity(std::make_shared<AnimeDefendersEngine::DamageZone>(
        //     m_sceneManager.getActiveScene(), "floor" + std::to_string(1), fileSystem, "floor2", Vector2f(0, -3), Vector2f(0.1, 0.5)));

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
