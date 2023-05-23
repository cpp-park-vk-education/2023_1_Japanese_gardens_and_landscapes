#include "Camera.hpp"

using namespace AnimeDefendersEngine::Graphics;

auto Camera::determineNewCameraTranspose() -> void {}

auto Camera::applyCameraView() -> void {}

auto Camera::setMotionRule(std::function<Math::Transpose()>) -> void {}

auto Camera::setExtraTranspose(Math::Transpose) -> void {}

auto Camera::setExtraMotion(std::function<Math::Transpose(Math::Transpose)>) -> void {}

auto Camera::setIsActive(bool) -> void {}
