#pragma once

#include <functional>

namespace AnimeDefendersEngine {

    class IWindow {
     public:
        virtual auto createWindow() -> void = 0;
        virtual auto destroyWindow() -> void = 0;
        virtual auto setWindowListener(std::function<void(void*)>) -> void = 0;
        virtual auto updateFrame() -> void = 0;
    };

}  // namespace AnimeDefendersEngine
