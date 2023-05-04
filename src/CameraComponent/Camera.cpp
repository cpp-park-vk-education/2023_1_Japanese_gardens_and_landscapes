#pragma once

#include "Camera.hpp"

auto Camera::determineNewCameraTranspose() -> void const {}

auto Camera::applyCameraView() -> void const {}

auto Camera::setMotionRule(std::function<Transpose()>) -> void {}

auto Camera::setExtraTranspose(Transpose) -> void {}

auto Camera::setExtraMotion(std::function<Transpose(Transpose)>) -> void {}

auto Camera::setIsActive(bool) -> void {}
