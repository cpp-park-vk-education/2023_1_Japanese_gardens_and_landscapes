#pragma once

#include "IWindow.hpp"

#include <string>

namespace AnimeDefendersEngine::Graphics {

    class Window final : public IWindow {
     public:
        Window(int, int, const std::string&) noexcept;

        ~Window() noexcept override;
        Window(const Window&) = delete;
        Window(Window&&) = delete;
        auto operator=(const Window&) -> Window& = delete;
        auto operator=(Window&&) -> Window& = delete;

        auto updateFrame() const noexcept -> void override;

        auto setMouseClickHandler(mouseClickHandler) const noexcept -> void override;
        auto setMouseMotionhandler(mouseMotionHandler) const noexcept -> void override;
        auto setKeyPressHandler(keyPressHandler) const noexcept -> void override;

     private:
        int m_windowId{};
        int m_windowWidth{};
        int m_windowHeidth{};
    };

}  // namespace AnimeDefendersEngine::Graphics
