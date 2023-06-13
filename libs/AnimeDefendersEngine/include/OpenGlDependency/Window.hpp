#pragma once

#include "IWindow.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class Window : public IWindow {
         public:
            auto createWindow() -> void override;
            auto destroyWindow() -> void override;
            auto setWindowListener(std::function<void(int, int, int)>) -> void override;
            auto updateFrame() -> void override;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
