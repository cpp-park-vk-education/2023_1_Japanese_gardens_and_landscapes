#include "Camera.hpp"
#include "Renderer.hpp"
#include "Sprite.hpp"
#include "UiElement.hpp"

#include <cassert>

using namespace AnimeDefendersEngine::Graphics;

Renderer::Renderer(std::shared_ptr<IWindow> window) : m_window(window) {
    m_window->createWindow();
}

auto Renderer::renderObjects(const Scene& scene) -> void {
    auto componentManager = scene.getComponentManager();

    auto cameras = componentManager->getComponents(typeid(Camera));
    auto sprites = componentManager->getComponents(typeid(Sprite));
    auto uiElements = componentManager->getComponents(typeid(UiElement));

    Camera* activeCamera{};
    Camera* nextCamera{};
    for (auto* nextCompenent : cameras) {
        nextCamera = static_cast<Camera*>(nextCompenent);

        if (nextCamera->isCameraActive()) {
            assert(!activeCamera);
            activeCamera = nextCamera;
        }
    }

    assert(activeCamera);

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
