#pragma once

#include "IWindow.hpp"

#include <string>

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

        auto setWindowMouseHandler(std::function<void(int, int, int, int)>) const noexcept -> void;
        auto setWindowMotionHandler(std::function<void(int, int)>) const noexcept -> void;
        auto setWindowKeyboardHandler(std::function<void(unsigned char, int, int)>) const noexcept -> void;

     private:
        int m_windowId{};
        int m_windowWidth{};
        int m_windowHeidth{};
    };

}  // namespace AnimeDefendersEngine::Graphics
