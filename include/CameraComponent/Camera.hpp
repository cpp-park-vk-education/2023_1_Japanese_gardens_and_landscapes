#pragma once

#include "Component.hpp"
#include "Transpose.hpp"

#include <functional>

namespace AnimeDefendersEngine {
    namespace Graphics {

        class Camera : public Component {
         public:
            auto determineNewCameraTranspose() -> void;
            auto applyCameraView() -> void const;

            auto setMotionRule(std::function<Transpose()>) -> void;
            auto setExtraTranspose(Transpose) -> void;
            auto setExtraMotion(std::function<Transpose(Transpose)>) -> void;
            auto setIsActive(bool) -> void;

         private:
            std::function<Transpose()> m_motionRule;
            Transpose m_cameraTranspose;
            std::function<Transpose(Transpose)> m_extraMotion;
            bool m_isActive;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
