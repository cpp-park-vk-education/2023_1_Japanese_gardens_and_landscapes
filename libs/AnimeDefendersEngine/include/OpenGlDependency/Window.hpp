#pragma once

#include "IWindow.hpp"

#include <string>

namespace AnimeDefendersEngine::Graphics {

    class Window final : public IWindow {
     public:
        Window(int windowWidth, int windowHeight, const std::string& windowTitle) noexcept;

        ~Window() noexcept override;
        Window(const Window&) = delete;
        Window(Window&&) = delete;
        auto operator=(const Window&) -> Window& = delete;
        auto operator=(Window&&) -> Window& = delete;

        auto updateFrame() const noexcept -> void override;

        auto setMouseClickHandler(mouseClickHandler) const noexcept -> void override;
        auto setActiveMouseMotionHandler(mouseMotionHandler) const noexcept -> void override;
        auto setPassiveMouseMotionHandler(mouseMotionHandler) const noexcept -> void override;
        auto setKeyPressHandler(keyPressHandler) const noexcept -> void override;

        auto isShiftPressed() const noexcept -> bool override;
        auto isCtrlPressed() const noexcept -> bool override;
        auto isAltPressed() const noexcept -> bool override;

     private:
        int m_windowId{};
        int m_windowWidth{};
        int m_windowHeight{};
    };

}  // namespace AnimeDefendersEngine::Graphics
