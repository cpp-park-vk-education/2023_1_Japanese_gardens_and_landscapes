#pragma once

#include <functional>
#include <string>

namespace AnimeDefendersEngine::Graphics {

    class IWindow {
     public:
        virtual auto updateFrame() const noexcept -> void = 0;

        virtual auto setWindowMouseHandler(void (*)(int, int, int, int)) const noexcept -> void = 0;
        virtual auto setWindowMotionHandler(void (*)(int, int)) const noexcept -> void = 0;
        virtual auto setWindowKeyboardHandler(void (*)(unsigned char, int, int)) const noexcept -> void = 0;
    };

}  // namespace AnimeDefendersEngine::Graphics
