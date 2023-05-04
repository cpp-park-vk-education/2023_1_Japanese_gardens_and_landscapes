#include "Camera.hpp"

using namespace AnimeDefendersEngine;

auto Camera::determineNewCameraTranspose() -> void {}

auto Camera::applyCameraView() -> void {}

auto Camera::setMotionRule(std::function<Transpose()>) -> void {}

auto Camera::setExtraTranspose(Transpose) -> void {}

auto Camera::setExtraMotion(std::function<Transpose(Transpose)>) -> void {}

auto Camera::setIsActive(bool) -> void {}
