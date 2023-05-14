#pragma once

#include <functional>

namespace AnimeDefendersEngine {
    namespace Graphics {

        class IWindow {
         public:
            virtual auto createWindow() -> void = 0;
            virtual auto destroyWindow() -> void = 0;
            virtual auto setWindowListener(std::function<void(int, int, int)>) -> void = 0;
            virtual auto updateFrame() -> void = 0;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
