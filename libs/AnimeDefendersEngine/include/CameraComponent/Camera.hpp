#pragma once

#include "Component.hpp"
#include "Transpose.hpp"

#include <functional>

namespace AnimeDefendersEngine::Graphics {

    class Camera final : public Component {
     public:
        explicit Camera(Math::Transpose*, std::function<void(Math::Transpose*)>, std::function<void(Math::Transpose*)>, bool) noexcept;

        auto determineNewCameraTranspose() const -> void;
        auto applyCameraView() const noexcept -> void;

        auto setTranspose(Math::Transpose*) noexcept -> void;
        auto setMotionRule(std::function<void(Math::Transpose*)>) noexcept -> void;
        auto setExtraMotion(std::function<void(Math::Transpose*)>) noexcept -> void;
        auto setIsActive(bool) noexcept -> void;

        [[nodiscard]] auto getCameraTranspose() const noexcept -> Math::Transpose*;
        [[nodiscard]] auto isActive() const noexcept -> bool;

     private:
        Math::Transpose* m_transpose;
        std::function<void(Math::Transpose*)> m_motionRule;
        std::function<void(Math::Transpose*)> m_extraMotion;
        bool m_isActive{false};
    };

}  // namespace AnimeDefendersEngine::Graphics
