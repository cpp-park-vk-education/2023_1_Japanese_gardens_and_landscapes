#include "CameraSystem.hpp"

using namespace AnimeDefendersEngine::Graphics;

auto CameraSystem::applyCameraView(const Camera* camera) -> void {
    transposeMathWrapper.applyTransposeMatrix(camera->getCameraTranspose());
}
