#pragma once

#include "BaseComponent.hpp"
#include "Transpose.hpp"

#include <functional>

namespace AnimeDefendersEngine::Graphics {

    using transposeChangingFunc = std::function<void(Math::Transpose&)>;

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
        Camera(const std::string& entityId, ComponentManager&, const Math::Transpose&, std::function<void(Math::Transpose&)> motionRule,
               std::function<void(Math::Transpose&)> extraMotion, bool isActive) noexcept;

        auto determineNewCameraTranspose() -> void;
        auto applyCameraView() const noexcept -> void;

        auto setTranspose(const Math::Transpose&) noexcept -> void;
        /// @brief Set function which sets new value to Transpose based on outer factors
        auto setMotionRuleFunc(transposeChangingFunc) noexcept -> void;
        /// @brief Set function which sets new value to Transpose based on inner state
        auto setExtraMotionFunc(transposeChangingFunc) noexcept -> void;
        auto setIsActive(bool) noexcept -> void;

        [[nodiscard]] auto getCameraTranspose() const noexcept -> const Math::Transpose&;
        [[nodiscard]] auto isActive() const noexcept -> bool;

     private:
        Math::Transpose m_transpose;
        /// @brief Function which sets new value to Transpose based on outer factors
        transposeChangingFunc m_motionRuleFunc;
        /// @brief Function which sets new value to Transpose based on inner state
        transposeChangingFunc m_extraMotionFunc;
        bool m_isActive{false};
    };

}  // namespace AnimeDefendersEngine::Graphics
