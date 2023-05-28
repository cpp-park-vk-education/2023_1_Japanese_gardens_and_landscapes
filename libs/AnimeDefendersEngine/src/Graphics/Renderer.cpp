#include "Renderer.hpp"
#include "Sprite.hpp"
#include "UiElement.hpp"

namespace AnimeDefendersEngine::Graphics {

    Renderer::Renderer(std::shared_ptr<IWindow> window) noexcept : m_window(window) {}

    auto Renderer::renderObjects(Scene& scene) -> void {
        auto componentManager = scene.getComponentManager();

        const auto& cameras = componentManager.getComponents<Camera>();
        const auto& sprites = componentManager.getComponents<Sprite>();
        const auto& uiElements = componentManager.getComponents<UiElement>();

        Camera* activeCamera{};
        for (const auto& compenent : cameras) {
            auto* camera = static_cast<Camera*>(compenent.second);

            if (camera->isActive()) {
                if (activeCamera) {
                    throw std::runtime_error("The active camera should be the only one! At the moment there are more.");
                }
                activeCamera = camera;
            }
        }

        if (!activeCamera) {
            throw std::runtime_error("The active camera should be the only one! At the moment they are not.");
        }

        activeCamera->determineNewCameraTranspose();
        activeCamera->applyCameraView();

        for (const auto& component : sprites) {
            const auto* sprite = static_cast<Sprite*>(component.second);

            if (sprite->isSpriteVisibleToCamera(activeCamera)) {
                sprite->drawSprite();
            }
        }

        for (const auto& component : uiElements) {
            auto* uiElement = static_cast<UiElement*>(component.second);

            uiElement->drawUiElement();
        }

        m_window->updateFrame();
    }

    auto Renderer::getActiveWindowPtr() const noexcept -> std::shared_ptr<IWindow> {
        return m_window;
    }

}  // namespace AnimeDefendersEngine::Graphics
