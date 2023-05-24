#include "Camera.hpp"
#include "Renderer.hpp"
#include "Sprite.hpp"
#include "UiElement.hpp"

namespace AnimeDefendersEngine::Graphics {

    Renderer::Renderer(std::shared_ptr<IWindow> window) : m_window(window) {
        m_window->createWindow(500, 500, "Anime Defenders: Battle Behind the Screen");
    }

    auto Renderer::renderObjects(Scene& scene) -> void {
        auto componentManager = scene.getComponentManager();

        auto cameras = componentManager.getComponents<Camera>();
        auto sprites = componentManager.getComponents<Sprite>();
        auto uiElements = componentManager.getComponents<UiElement>();

        Camera* activeCamera{};
        for (const auto& nextCompenent : cameras) {
            auto* camera = static_cast<Camera*>(nextCompenent.second);

            if (camera->isCameraActive()) {
                if (activeCamera) {
                    throw std::runtime_error("Active camera must be the only one!");
                }
                activeCamera = camera;
            }
        }

        if (!activeCamera) {
            throw std::runtime_error("One of all cameras must be active!");
        }

        activeCamera->determineNewCameraTranspose();
        activeCamera->applyCameraView();

        for (const auto& nextComponent : sprites) {
            auto* sprite = static_cast<Sprite*>(nextComponent.second);

            if (sprite->isSpriteVisibleToCamera(activeCamera)) {
                sprite->drawSprite();
            }
        }

        for (const auto& nextComponent : uiElements) {
            auto* uiElement = static_cast<UiElement*>(nextComponent.second);

            uiElement->drawUiElement();
        }

        m_window->updateFrame();
    }

}  // namespace AnimeDefendersEngine::Graphics
