#pragma once

#include "Camera.hpp"
#include "ISystem.hpp"
#include "TransposeMathWrapper.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class CameraSystem : public ISystem {
         public:
            static auto applyCameraView(const Camera*) -> void;

         private:
            static constexpr TransposeMathWrapper transposeMathWrapper{};
            CameraSystem();
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
