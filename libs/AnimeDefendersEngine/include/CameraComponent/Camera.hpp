#pragma once

#include "BaseComponent.hpp"
#include "Transpose.hpp"

#include <functional>

namespace AnimeDefendersEngine::Graphics {

    class Camera final : public BaseComponent<Camera> {
     public:
        /**
         * Default constructor of camera
         *
         * @param motionRule Function which sets new value to Transpose
         *                   based on outer factors
         *
         * @param extraMotion Function which sets new value to Transpose
         *                    based on inner state
         */
        explicit Camera(const std::string& entityId, const Math::Transpose&, std::function<void(Math::Transpose&)> motionRule,
                        std::function<void(Math::Transpose&)> extraMotion, bool isActive) noexcept;

        auto determineNewCameraTranspose() -> void;
        auto applyCameraView() const noexcept -> void;

        auto setTranspose(const Math::Transpose&) noexcept -> void;
        auto setMotionRule(std::function<void(Math::Transpose&)>) noexcept -> void;
        auto setExtraMotion(std::function<void(Math::Transpose&)>) noexcept -> void;
        auto setIsActive(bool) noexcept -> void;

        [[nodiscard]] auto getCameraTranspose() const noexcept -> const Math::Transpose&;
        [[nodiscard]] auto isActive() const noexcept -> bool;

     private:
        Math::Transpose m_transpose;
        /// @brief Function which sets new value to Transpose based on outer factors
        std::function<void(Math::Transpose&)> m_motionRule;
        /// @brief Function which sets new value to Transpose based on inner state
        std::function<void(Math::Transpose&)> m_extraMotion;
        bool m_isActive{false};
    };

}  // namespace AnimeDefendersEngine::Graphics
