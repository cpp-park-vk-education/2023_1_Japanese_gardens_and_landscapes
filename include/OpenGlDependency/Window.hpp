#pragma once

#include "IWindow.hpp"

namespace AnimeDefendersEngine {

    class Window : public IWindow {
     public:
        auto createWindow() -> void override;
        auto destroyWindow() -> void override;
        auto setWindowListener(std::function<void(void*)>) -> void override;
        auto updateFrame() -> void override;
    };

}  // namespace AnimeDefendersEngine
