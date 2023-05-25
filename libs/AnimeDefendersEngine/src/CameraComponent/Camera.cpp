#include "Camera.hpp"
#include "CameraSystem.hpp"

namespace AnimeDefendersEngine::Graphics {

    Camera::Camera(
        const std::string& entityId, ComponentManager& componentManager, const Math::Transpose& transpose,
        transposeChangingFunctor motionRuleFunctor = [](Math::Transpose&) {},
        transposeChangingFunctor extraMotionFunctor = [](Math::Transpose&) {}, bool isActive = true) noexcept
        : BaseComponent<Camera>(entityId, componentManager),
          m_transpose(transpose),
          m_motionRuleFunctor(motionRuleFunctor),
          m_extraMotionFunctor(extraMotionFunctor),
          m_isActive(isActive) {}

    auto Camera::determineNewCameraTranspose() -> void {
        m_motionRuleFunctor(m_transpose);
        m_extraMotionFunctor(m_transpose);
    }

    auto Camera::applyCameraView() const noexcept -> void {
        CameraSystem::applyCameraView(this);
    }

    auto Camera::setTranspose(const Math::Transpose& transpose) noexcept -> void {
        m_transpose = transpose;
    }

    auto Camera::setMotionRuleFunctor(transposeChangingFunctor motionRuleFunctor) noexcept -> void {
        m_motionRuleFunctor = motionRuleFunctor;
    }

    auto Camera::setExtraMotionFunctor(transposeChangingFunctor extraMotionFunctor) noexcept -> void {
        m_extraMotionFunctor = extraMotionFunctor;
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
