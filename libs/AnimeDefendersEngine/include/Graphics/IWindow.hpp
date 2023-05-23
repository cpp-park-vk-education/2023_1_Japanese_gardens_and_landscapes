#pragma once

#include <functional>

namespace AnimeDefendersEngine::Graphics {

    using mouseClickHandler = std::function<void(int buttonNum, int buttonState, int xMouse, int yMouse)>;
    using mouseMotionHandler = std::function<void(int xMouse, int yMouse)>;
    using keyPressHandler = std::function<void(unsigned char keyChar, int xMouse, int yMouse)>;

    class IWindow {
     public:
        virtual ~IWindow() = default;

        virtual auto updateFrame() const noexcept -> void = 0;

        virtual auto setMouseClickHandler(mouseClickHandler) const noexcept -> void = 0;
        virtual auto setMouseMotionhandler(mouseMotionHandler) const noexcept -> void = 0;
        virtual auto setKeyPressHandler(keyPressHandler) const noexcept -> void = 0;
    };

}  // namespace AnimeDefendersEngine::Graphics
