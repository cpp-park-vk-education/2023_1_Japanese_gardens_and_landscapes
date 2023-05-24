#include "CameraSystem.hpp"
#include "TransposeMathWrapper.hpp"

namespace AnimeDefendersEngine::Graphics::CameraSystem {

    namespace {
        const TransposeMathWrapper transposeMathWrapper{};
    }

    auto applyCameraView(const Camera* camera) -> void {
        transposeMathWrapper.applyTransposeMatrix(camera->getCameraTranspose());
    }

}  // namespace AnimeDefendersEngine::Graphics::CameraSystem
