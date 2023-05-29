#include "SceneLoader.hpp"
#include "Entity.hpp"
#include "IEntityCreator.hpp"
#include "Logger.hpp"
#include "Scene.hpp"
#include "SceneManager.hpp"
#include "TableReader.hpp"

namespace {

    constexpr char entityParameterSeparator = '|';
    constexpr std::size_t idIndex = 0;

}  // namespace

namespace AnimeDefendersEngine {

    auto SceneLoader::m_loadScenes() -> void {
        while (!m_dataStream->eof()) {
            std::string line{};
            std::getline(*m_dataStream, line);
            auto entityParameters = FileSystem::splitString(line, entityParameterSeparator);

            if (entityParameters.empty()) {
                continue;
            }

            std::size_t id{};

            try {
                id = std::stoul(entityParameters[idIndex]);
            } catch (std::exception& ex) {
                Logger::defaultLog.printError(ex.what());
                continue;
            }

            if (!m_sceneManager.getScenes().contains(id)) {
                m_sceneManager.getScenes()[id] = std::make_unique<Scene>(id);
            }

            auto& scene = *m_sceneManager.getScenes()[id];
            scene.addEntity(m_creator->create(entityParameters, scene));
        }
    }

    SceneLoader::SceneLoader(std::unique_ptr<std::istream> dataStream, std::unique_ptr<IEntityCreator> creator, SceneManager& sceneManager)
        : m_dataStream{std::move(dataStream)}, m_creator{std::move(creator)}, m_sceneManager{sceneManager} {
        m_loadScenes();
    }

}  // namespace AnimeDefendersEngine
