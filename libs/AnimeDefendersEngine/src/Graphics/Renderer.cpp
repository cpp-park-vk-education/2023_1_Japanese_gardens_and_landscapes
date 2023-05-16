#include "Camera.hpp"
#include "Renderer.hpp"
#include "Sprite.hpp"
#include "UiElement.hpp"

#include <cassert>
#include <ranges>

using namespace AnimeDefendersEngine::Graphics;

Renderer::Renderer(std::shared_ptr<IWindow> window) : m_window(window) {
    m_window->createWindow();
}

auto Renderer::renderObjects(const Scene& scene) -> void {
    auto componentManager = scene.getComponentManager();

    auto cameras = componentManager->getComponents(typeid(Camera));
    auto sprites = componentManager->getComponents(typeid(Sprite));
    auto uiElements = componentManager->getComponents(typeid(UiElement));

    std::vector<Component*> activeCameras =
        std::as_const(cameras) | std::ranges::views::filter([](const auto& camera) { return camera->isCameraActive(); });

    assert(activeCameras.size() == 1);

    auto activeCamera = activeCameras.at(0);
    activeCamera->determineNewCameraTransform();
    activeCamera->applyCameraView();

    std::as_const(sprites) | std::ranges::views::filter([](const auto& sprite) { return sprite->isSpriteVisibleToCamera(activeCamera); }) |
        std::ranges::views::transform([](const auto& sprite) { return sprite->drawSprite(); });

    std::as_const(uiElements) | std::ranges::views::transform([](const auto& uiElement) { return uiElement->drawUiElement(); });

    m_window->updateFrame();
}
