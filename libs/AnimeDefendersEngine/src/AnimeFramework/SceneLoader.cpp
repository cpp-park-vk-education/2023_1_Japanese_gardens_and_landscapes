#include "SceneLoader.hpp"
#include "Entity.hpp"
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
            std::string line;
            std::getline(*m_dataStream, line);
            auto entityParameters = FileSystem::splitString(line, entityParameterSeparator);

            if (!entityParameters.empty()) {
                std::size_t id = std::stoul(entityParameters[idIndex]);

                if (!m_sceneManager.m_scenes.contains(id)) {
                    m_sceneManager.m_scenes[id] = std::make_unique<Scene>(id);
                }

                auto& scene = *m_sceneManager.m_scenes[id];

                scene.addEntity(m_creator->create(entityParameters, scene));
            }
        }
    }

    SceneLoader::SceneLoader(std::unique_ptr<std::istream> dataStream, std::unique_ptr<IEntityCreator> creator, SceneManager& sceneManager)
        : m_dataStream{std::move(dataStream)}, m_creator{std::move(creator)}, m_sceneManager{sceneManager} {
        m_loadScenes();
    }

}  // namespace AnimeDefendersEngine