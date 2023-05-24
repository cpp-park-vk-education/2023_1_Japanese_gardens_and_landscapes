#include "Camera.hpp"
#include "Renderer.hpp"
#include "Sprite.hpp"
#include "UiElement.hpp"

namespace AnimeDefendersEngine::Graphics {

    Renderer::Renderer(std::shared_ptr<IWindow> window) : m_window(window) {
        m_window->createWindow(500, 500, "Anime Defenders: Battle Behind the Screen");
    }

    auto Renderer::renderObjects(const Scene& scene) -> void {
        auto componentManager = scene.getComponentManager();

        auto cameras = componentManager->getComponents<Camera>();
        auto sprites = componentManager->getComponents<Sprite>();
        auto uiElements = componentManager->getComponents<UiElement>();

        Camera* activeCamera{};
        Camera* nextCamera{};
        for (auto* nextCompenent : cameras) {
            nextCamera = static_cast<Camera*>(nextCompenent);

            if (nextCamera->isCameraActive()) {
                if (activeCamera) {
                    throw std::runtime_error("Active camera must be the only one!");
                }
                activeCamera = nextCamera;
            }
        }

        if (!activeCamera) {
            throw std::runtime_error("One of all cameras must be active!");
        }

        activeCamera->determineNewCameraTransform();
        activeCamera->applyCameraView();

        Sprite* nextSprite{};
        for (auto* nextComponent : sprites) {
            nextSprite = static_cast<Sprite*>(nextComponent);

            if (nextSprite->isSpriteVisibleToCamera(activeCamera)) {
                nextSprite->drawSprite();
            }
        }

        UiElement* nextUiElement{};
        for (auto* nextComponent : uiElements) {
            nextUiElement = static_cast<UiElement*>(nextComponent);

            nextUiElement->drawUiElement();
        }

        m_window->updateFrame();
    }

}  // namespace AnimeDefendersEngine::Graphics
