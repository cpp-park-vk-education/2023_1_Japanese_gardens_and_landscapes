#include "Camera.hpp"

using namespace AnimeDefendersEngine::Graphics;

auto Camera::determineNewCameraTransform() -> void {}

auto Camera::applyCameraView() -> void {}

auto Camera::setMotionRule(std::function<Transform()>) -> void {}

auto Camera::setExtraTransform(Transform) -> void {}

auto Camera::setExtraMotion(std::function<Transform(Transform)>) -> void {}

auto Camera::setIsActive(bool) -> void {}
