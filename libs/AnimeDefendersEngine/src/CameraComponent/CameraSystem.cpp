#include "CameraSystem.hpp"

namespace AnimeDefendersEngine::Graphics::CameraSystem {

    auto applyCameraView(const Camera* camera) -> void {
        transposeMathWrapper.applyTransposeMatrix(camera->getCameraTranspose());
    }

}  // namespace AnimeDefendersEngine::Graphics::CameraSystem
