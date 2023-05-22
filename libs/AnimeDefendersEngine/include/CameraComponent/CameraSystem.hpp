#pragma once

#include "Camera.hpp"
#include "ISystem.hpp"
#include "TransposeMathWrapper.hpp"

namespace AnimeDefendersEngine::Graphics::CameraSystem {

    auto applyCameraView(const Camera*) -> void;

    constexpr TransposeMathWrapper transposeMathWrapper{};

}  // namespace AnimeDefendersEngine::Graphics::CameraSystem
