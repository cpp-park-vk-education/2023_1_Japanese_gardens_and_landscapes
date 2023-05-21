#pragma once

#include "Camera.hpp"
#include "ISystem.hpp"
#include "TransposeMathWrapper.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class CameraSystem : public ISystem {
         public:
            auto updateSystem(ComponentManager&) -> void;

            static auto applyCameraView(const Camera*) -> void;

         private:
            CameraSystem();

            static constexpr TransposeMathWrapper transposeMathWrapper{};
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
