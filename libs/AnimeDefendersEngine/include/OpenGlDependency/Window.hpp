#pragma once

#include "IWindow.hpp"

#include <iostream>

namespace AnimeDefendersEngine {
    namespace Graphics {

        class Window : public IWindow {
         public:
            auto createWindow() const -> void override;
            auto destroyWindow() const -> void override;
            auto setWindowListener(std::function<void(int, int, int)>) const -> void override;
            auto updateFrame() const -> void override;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
