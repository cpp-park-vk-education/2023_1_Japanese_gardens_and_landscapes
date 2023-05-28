#include "Renderer.hpp"
#include "Sprite.hpp"
#include "UiElement.hpp"

namespace AnimeDefendersEngine::Graphics {

    Renderer::Renderer(std::shared_ptr<IWindow> window) noexcept : m_window(window) {}

    auto Renderer::renderObjects(Scene& scene) -> void {
        auto componentManager = scene.getComponentManager();

        auto cameras = componentManager.getComponents<Camera>();
        auto sprites = componentManager.getComponents<Sprite>();
        auto uiElements = componentManager.getComponents<UiElement>();

        Camera* activeCamera{};
        for (const auto& nextCompenent : cameras) {
            auto* camera = static_cast<Camera*>(nextCompenent.second);

            if (camera->isActive()) {
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
            const auto* sprite = static_cast<Sprite*>(nextComponent.second);

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

    auto Renderer::getActiveWindowPtr() const noexcept -> std::shared_ptr<IWindow> {
        return m_window;
    }

}  // namespace AnimeDefendersEngine::Graphics
