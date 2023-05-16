#pragma once

#include "Camera.hpp"
#include "ISystem.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class CameraSystem : public ISystem {
         public:
            static auto determineNewCameraTranspose(const Camera&) -> void;
            static auto applyCameraView(const Camera&) -> void;

         private:
            CameraSystem();
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
