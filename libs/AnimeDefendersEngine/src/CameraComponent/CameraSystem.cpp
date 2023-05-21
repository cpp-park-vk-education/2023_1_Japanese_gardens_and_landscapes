#include "CameraSystem.hpp"

using namespace AnimeDefendersEngine::Graphics;

auto CameraSystem::updateSystem(ComponentManager&) -> void {}

auto CameraSystem::applyCameraView(const Camera* camera) -> void {
    transposeMathWrapper.applyTransposeMatrix(camera->getCameraTranspose());
}
