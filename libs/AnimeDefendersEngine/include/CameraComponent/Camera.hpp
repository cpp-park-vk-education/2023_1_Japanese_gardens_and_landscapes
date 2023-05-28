#pragma once

#include "BaseComponent.hpp"
#include "Transpose.hpp"
#include "TransposeMathWrapper.hpp"

#include <functional>
#include <typeinfo>

namespace AnimeDefendersEngine::Graphics {

    class Camera final : public BaseComponent<Camera> {
     public:
        using transposeChangingFunctor = std::function<void(Math::Transpose&)>;

        /**
         * Default constructor of camera
         *
         * @param motionRule Function which sets new value to Transpose
         *                   based on outer factors
         *
         * @param extraMotion Function which sets new value to Transpose
         *                    based on inner state
         */
        Camera(const std::string& entityId, ComponentManager&, const Math::Transpose&, transposeChangingFunctor motionRule,
               transposeChangingFunctor extraMotion, bool isActive) noexcept;

        auto determineNewCameraTranspose() -> void;
        auto applyCameraView() const noexcept -> void;

        auto setTranspose(const Math::Transpose&) noexcept -> void;
        /// @brief Set functor which sets new value to Transpose based on outer factors
        auto setMotionRuleFunctor(transposeChangingFunctor) noexcept -> void;
        /// @brief Set functor which sets new value to Transpose based on inner state
        auto setExtraMotionFunctor(transposeChangingFunctor) noexcept -> void;
        auto setActive(bool) noexcept -> void;

        [[nodiscard]] auto getCameraTranspose() const noexcept -> const Math::Transpose&;
        [[nodiscard]] auto isActive() const noexcept -> bool;
        [[nodiscard]] auto getTransposeMathWrapper() const noexcept -> const ITransposeMathWrapper&;

     private:
        Math::Transpose m_transpose;
        /// @brief Functor which sets new value to Transpose based on outer factors
        transposeChangingFunctor m_motionRuleFunctor;
        /// @brief Functor which sets new value to Transpose based on inner state
        transposeChangingFunctor m_extraMotionFunctor;
        bool m_isActive{false};

        const TransposeMathWrapper m_transposeMathWrapper;
    };

}  // namespace AnimeDefendersEngine::Graphics
