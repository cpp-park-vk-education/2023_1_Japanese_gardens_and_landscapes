#pragma once

#include "Component.hpp"
#include "Transpose.hpp"

#include <functional>

namespace AnimeDefendersEngine {
    namespace Graphics {

        class Camera : public Component {
         public:
            Camera(Transpose, std::function<Transpose()>, std::function<Transpose(Transpose)>, bool);

            auto determineNewCameraTranspose() const -> void;
            auto applyCameraView() const -> void;

            auto setTranspose(Transpose) -> void;
            auto setMotionRule(std::function<Transpose()>) -> void;
            auto setExtraMotion(std::function<Transpose(Transpose)>) -> void;
            auto setIsActive(bool) -> void;

            auto getCameraTranspose() const -> Transpose;
            auto isActive() const -> bool;

         private:
            Transpose m_transpose;
            std::function<Transpose()> m_motionRule;
            std::function<Transpose(Transpose)> m_extraMotion;
            bool m_isActive;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
