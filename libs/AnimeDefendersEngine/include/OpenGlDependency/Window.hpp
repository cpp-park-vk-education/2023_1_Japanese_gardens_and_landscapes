#pragma once

#include "IWindow.hpp"

#include <iostream>

namespace AnimeDefendersEngine {
    namespace Graphics {

        class Window : public IWindow {
         public:
            Window(int, int, const std::string&);
            ~Window();
            auto updateFrame() const -> void override;

            auto setWindowMouseListener(void (*)(int, int, int, int)) const -> void;
            auto setWindowMotionListener(void (*)(int, int)) const -> void;
            auto setWindowKeyboardListener(void (*)(unsigned char, int, int)) const -> void;

         private:
            int m_windowId{};
            int m_windowWidth{};
            int m_windowHeidth{};
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
