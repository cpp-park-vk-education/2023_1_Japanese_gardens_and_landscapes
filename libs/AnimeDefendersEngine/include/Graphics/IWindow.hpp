#pragma once

#include <functional>

namespace AnimeDefendersEngine::Graphics {

    using mouseClickHandler = std::function<void(int, int, int, int)>;
    using mouseMotionHandler = std::function<void(int, int)>;
    using keyPressHandler = std::function<void(unsigned char, int, int)>;

    class IWindow {
     public:
        virtual ~IWindow() = default;

        virtual auto updateFrame() const noexcept -> void = 0;

        virtual auto setMouseClickHandler(mouseClickHandler) const noexcept -> void = 0;
        virtual auto setMouseMotionhandler(mouseMotionHandler) const noexcept -> void = 0;
        virtual auto setKeyPressHandler(keyPressHandler) const noexcept -> void = 0;
    };

}  // namespace AnimeDefendersEngine::Graphics
