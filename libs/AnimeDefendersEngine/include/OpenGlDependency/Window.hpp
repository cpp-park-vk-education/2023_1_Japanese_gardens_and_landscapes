#pragma once

#include "IWindow.hpp"

#include <iostream>

namespace AnimeDefendersEngine::Graphics {

    class Window final : public IWindow {
     public:
        Window(int, int, const std::string&);
        ~Window();
        auto updateFrame() const -> void override;

        auto setWindowMouseHandler(void (*)(int, int, int, int)) const -> void;
        auto setWindowMotionHandler(void (*)(int, int)) const -> void;
        auto setWindowKeyboardHandler(void (*)(unsigned char, int, int)) const -> void;

     private:
        int m_windowId{};
        int m_windowWidth{};
        int m_windowHeidth{};
    };

}  // namespace AnimeDefendersEngine::Graphics
