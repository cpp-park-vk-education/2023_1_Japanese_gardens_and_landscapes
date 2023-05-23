#include "Camera.hpp"
#include "CameraSystem.hpp"

namespace AnimeDefendersEngine::Graphics {

    Camera::Camera(
        Math::Transpose* transpose, std::function<void(Math::Transpose*)> motionRule = [](Math::Transpose*) {},
        std::function<void(Math::Transpose*)> extraMotion = [](Math::Transpose*) {}, bool isActive = true) noexcept
        : m_transpose(transpose), m_motionRule(motionRule), m_extraMotion(extraMotion), m_isActive(isActive) {}

    auto Camera::determineNewCameraTranspose() const -> void {
        m_motionRule(m_transpose);
        m_extraMotion(m_transpose);
    }

    auto Camera::applyCameraView() const noexcept -> void {
        CameraSystem::applyCameraView(this);
    }

    auto Camera::setTranspose(Math::Transpose* transpose) noexcept -> void {
        m_transpose = transpose;
    }

    auto Camera::setMotionRule(std::function<void(Math::Transpose*)> motionRule) noexcept -> void {
        m_motionRule = motionRule;
    }

    auto Camera::setExtraMotion(std::function<void(Math::Transpose*)> extraMotion) noexcept -> void {
        m_extraMotion = extraMotion;
    }

    auto Camera::setIsActive(bool isActive) noexcept -> void {
        m_isActive = isActive;
    }

    auto Camera::getCameraTranspose() const noexcept -> Math::Transpose* {
        return m_transpose;
    }

    auto Camera::isActive() const noexcept -> bool {
        return m_isActive;
    }

}  // namespace AnimeDefendersEngine::Graphics
