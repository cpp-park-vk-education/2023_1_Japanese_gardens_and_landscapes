#include "Camera.hpp"
#include "CameraSystem.hpp"

using namespace AnimeDefendersEngine::Graphics;

Camera::Camera(
    Transpose transpose = Transpose{}, std::function<Transpose()> motionRule = []() { return Transpose{}; },
    std::function<Transpose(Transpose)> extraMotion = [](Transpose trnaspose) { return transpose }, bool isActive = true)
    : m_transose(transpose), m_motionRule(motionRule), m_extraMotion(extraMotion), m_isActive(isActive) {}

auto Camera::determineNewCameraTranspose() const -> void {
    m_transpose = m_extraMotion(m_motionRule());
}

auto Camera::applyCameraView() const -> void {
    CameraSystem::applyCameraView(this);
}

auto Camera::setTranspose(Transpose transpose) -> void {
    m_transpose = transpose;
}

auto Camera::setMotionRule(std::function<Transpose()> motionRule) -> void {
    m_motionRule = motionRule;
}

auto Camera::setExtraMotion(std::function<Transpose(Transpose)> extraMotion) -> void {
    m_extraMotion = extraMotion;
}

auto Camera::setIsActive(bool isActive) -> void {
    m_isActive = isActive;
}

auto Camera::getCameraTranspose() const -> Transpose {
    return m_transpose;
}

auto Camera::isActive() const -> bool {
    return m_isActive;
}
