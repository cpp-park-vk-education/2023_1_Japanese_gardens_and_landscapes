#pragma once

#include "IWindow.hpp"

#include <iostream>

namespace AnimeDefendersEngine {
    namespace Graphics {

        class Window : public IWindow {
         public:
            auto createWindow() -> void override;
            auto destroyWindow() -> void override;
            auto updateFrame() const -> void override;

            auto setWindowMouseListener(void (*)(int, int, int, int)) const -> void;
            auto setWindowMotionListener(void (*)(int, int)) const -> void;
            auto setWindowKeyboardListener(void (*)(unsigned char, int, int)) const -> void;

         private:
            int m_windowId{};
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
