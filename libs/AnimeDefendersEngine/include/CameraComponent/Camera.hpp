#pragma once

#include "Component.hpp"
#include "Transpose.hpp"

#include <functional>

namespace AnimeDefendersEngine::Graphics {

    class Camera final : public Component {
     public:
        Camera(Transpose*, std::function<void(Transpose*)>, std::function<void(Transpose*)>, bool) noexcept;

        auto determineNewCameraTranspose() const -> void;
        auto applyCameraView() const noexcept -> void;

        auto setTranspose(Transpose*) noexcept -> void;
        auto setMotionRule(std::function<void(Transpose*)>) noexcept -> void;
        auto setExtraMotion(std::function<void(Transpose*)>) noexcept -> void;
        auto setIsActive(bool) -> void;

        [[nodiscard]] auto getCameraTranspose() const noexcept -> Transpose*;
        [[nodiscard]] auto isActive() const noexcept -> bool;

     private:
        Transpose* m_transpose;
        std::function<void(Transpose*)> m_motionRule;
        std::function<void(Transpose*)> m_extraMotion;
        bool m_isActive{false};
    };

}  // namespace AnimeDefendersEngine::Graphics
