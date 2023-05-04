#include "GameLoop.hpp"
#include "ISystem.hpp"
#include "SystemManager.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace Mocks {
    using namespace AnimeDefendersEngine;
    class SystemManager : public ISystemManager {
     public:
        MOCK_METHOD(void, updateSystems, (IComponentManager&), (override));
    };

    class System : public ISystem {
     public:
        MOCK_METHOD(void, updateSystem, (IComponentManager&), (override));
    };

    class SceneManager : public ISceneManager {
     public:
        MOCK_METHOD(Scene&, getActiveScene, (), (override));
        MOCK_METHOD(void, loadSceme, (int), (override));
    };

}  // namespace Mocks

TEST(GAMELOOP, InvalidPointer) {
    using namespace AnimeDefendersEngine;
    GameLoop loop;
    EXPECT_THROW(loop.run(), std::runtime_error);
}

using ::testing::AtLeast;

TEST(GameLoop, SystemManagerCall) {
    using namespace AnimeDefendersEngine;
    Scene emptyScene;
    auto sceneManager = std::make_shared<SceneManager>();
    sceneManager->addScene(emptyScene);

    auto systemManager = std::make_unique<Mocks::SystemManager>();
    auto mockClass = systemManager.get();
    auto eventManager = std::make_unique<EventManager>();

    GameLoop loop;
    loop.setSystemManager(std::move(systemManager));
    loop.setEventManager(std::move(eventManager));
    loop.setSceneManager(sceneManager);

    EXPECT_CALL(*mockClass, updateSystems(*emptyScene.getComponents())).Times(AtLeast(1));
    loop.run();
}

TEST(GameLoop, SceneManagerCall) {
    using namespace AnimeDefendersEngine;

    auto sceneManager = std::make_shared<Mocks::SceneManager>();

    auto systemManager = std::make_unique<Mocks::SystemManager>();
    auto mockClass = systemManager.get();
    auto eventManager = std::make_unique<EventManager>();

    GameLoop loop;
    loop.setSystemManager(std::move(systemManager));
    loop.setEventManager(std::move(eventManager));
    loop.setSceneManager(sceneManager);

    EXPECT_CALL(*sceneManager, getActiveScene()).Times(AtLeast(1));
    loop.run();
}

namespace {
    class LocalSystemManager : public AnimeDefendersEngine::SystemManager {
     public:
        LocalSystemManager(AnimeDefendersEngine::ISystem* system) { m_systems.push_back(system); }
    };

}  // namespace

TEST(SystemManager, SystemCall) {
    using namespace AnimeDefendersEngine;

    auto system = std::make_unique<Mocks::System>();
    auto components = std::make_unique<ComponentManager>();

    LocalSystemManager systemManager(system.get());

    EXPECT_CALL(*system.get(), updateSystem(*components)).Times(AtLeast(1));
    systemManager.updateSystems(*components);
}

