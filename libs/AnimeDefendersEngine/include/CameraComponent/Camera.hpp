#pragma once

#include "Component.hpp"
#include "Transpose.hpp"

#include <functional>

namespace AnimeDefendersEngine {
    namespace Graphics {

        class Camera : public Component {
         public:
            auto determineNewCameraTranspose() -> void;
            auto applyCameraView() -> void;

            auto setMotionRule(std::function<Math::Transpose()>) -> void;
            auto setExtraTranspose(Math::Transpose) -> void;
            auto setExtraMotion(std::function<Math::Transpose(Math::Transpose)>) -> void;
            auto setIsActive(bool) -> void;

         private:
            std::function<Math::Transpose()> m_motionRule;
            Math::Transpose m_cameraTranspose;
            std::function<Math::Transpose(Math::Transpose)> m_extraMotion;
            bool m_isActive;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
