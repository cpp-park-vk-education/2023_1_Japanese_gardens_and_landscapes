#pragma once

#include "IWindow.hpp"

namespace AnimeDefendersEngine::Graphics {

    class Window final : public IWindow {
     public:
        Window(int, int, const std::string&) noexcept;

        ~Window() noexcept;
        Window(const Window&) = delete;
        Window(Window&&) = delete;
        auto operator=(const Window&) -> Window& = delete;
        auto operator=(Window&&) -> Window& = delete;

        auto updateFrame() const noexcept -> void override;

        auto setWindowMouseHandler(void (*)(int, int, int, int)) const noexcept -> void;
        auto setWindowMotionHandler(void (*)(int, int)) const noexcept -> void;
        auto setWindowKeyboardHandler(void (*)(unsigned char, int, int)) const noexcept -> void;

     private:
        int m_windowId{};
        int m_windowWidth{};
        int m_windowHeidth{};
    };

}  // namespace AnimeDefendersEngine::Graphics
