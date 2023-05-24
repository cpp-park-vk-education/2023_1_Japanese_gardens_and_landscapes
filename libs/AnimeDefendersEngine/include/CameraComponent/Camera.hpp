#pragma once

#include "Component.hpp"
#include "Transform.hpp"

#include <functional>
#include <typeinfo>

namespace AnimeDefendersEngine {
    namespace Graphics {

        class Camera : public Component {
         public:
            auto determineNewCameraTransform() -> void;
            auto applyCameraView() -> void;

            auto setMotionRule(std::function<Transform()>) -> void;
            auto setExtraTransform(Transform) -> void;
            auto setExtraMotion(std::function<Transform(Transform)>) -> void;
            auto setIsActive(bool) -> void;

         private:
            std::function<Transform()> m_motionRule;
            Transform m_cameraTransform;
            std::function<Transform(Transform)> m_extraMotion;
            bool m_isActive;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
