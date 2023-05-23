#pragma once

#include <functional>

namespace AnimeDefendersEngine::Graphics {

    class IWindow {
     public:
        virtual auto updateFrame() const noexcept -> void = 0;

        virtual ~IWindow() = default;

        virtual auto setWindowMouseHandler(std::function<void(int, int, int, int)>) const noexcept -> void = 0;
        virtual auto setWindowMotionHandler(std::function<void(int, int)>) const noexcept -> void = 0;
        virtual auto setWindowKeyboardHandler(std::function<void(unsigned char, int, int)>) const noexcept -> void = 0;
    };

}  // namespace AnimeDefendersEngine::Graphics
