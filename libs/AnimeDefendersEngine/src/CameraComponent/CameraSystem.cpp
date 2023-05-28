#include "CameraSystem.hpp"
#include "TransposeMathWrapper.hpp"

namespace AnimeDefendersEngine::Graphics::CameraSystem {

    auto applyCameraView(const Camera* camera) -> void {
        const auto& transposeMathWrapper = camera->getTransposeMathWrapper();

        transposeMathWrapper.applyTransposeMatrix(camera->getCameraTranspose());
    }

}  // namespace AnimeDefendersEngine::Graphics::CameraSystem
