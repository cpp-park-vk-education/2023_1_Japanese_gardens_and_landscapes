#include "Camera.hpp"
#include "CameraSystem.hpp"

namespace AnimeDefendersEngine::Graphics {

    Camera::Camera(
        const std::string& entityId, ComponentManager& componentManager, const Math::Transpose& transpose,
        std::function<void(Math::Transpose&)> motionRuleFunc = [](Math::Transpose&) {},
        std::function<void(Math::Transpose&)> extraMotionFunc = [](Math::Transpose&) {}, bool isActive = true) noexcept
        : BaseComponent<Camera>(entityId, componentManager),
          m_transpose(transpose),
          m_motionRuleFunc(motionRuleFunc),
          m_extraMotionFunc(extraMotionFunc),
          m_isActive(isActive) {}

    auto Camera::determineNewCameraTranspose() -> void {
        m_motionRuleFunc(m_transpose);
        m_extraMotionFunc(m_transpose);
    }

    auto Camera::applyCameraView() const noexcept -> void {
        CameraSystem::applyCameraView(this);
    }

    auto Camera::setTranspose(const Math::Transpose& transpose) noexcept -> void {
        m_transpose = transpose;
    }

    auto Camera::setMotionRuleFunc(transposeChangingFunc motionRuleFunc) noexcept -> void {
        m_motionRuleFunc = motionRuleFunc;
    }

    auto Camera::setExtraMotionFunc(transposeChangingFunc extraMotionFunc) noexcept -> void {
        m_extraMotionFunc = extraMotionFunc;
    }

    auto Camera::setIsActive(bool isActive) noexcept -> void {
        m_isActive = isActive;
    }

    auto Camera::getCameraTranspose() const noexcept -> const Math::Transpose& {
        return m_transpose;
    }

    auto Camera::isActive() const noexcept -> bool {
        return m_isActive;
    }

}  // namespace AnimeDefendersEngine::Graphics
