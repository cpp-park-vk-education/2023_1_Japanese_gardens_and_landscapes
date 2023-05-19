#pragma once

#include <functional>
#include <string>

namespace AnimeDefendersEngine {
    namespace Graphics {

        class IWindow {
         public:
            virtual auto updateFrame() const -> void = 0;

            virtual auto setWindowMouseListener(void (*)(int, int, int, int)) const -> void = 0;
            virtual auto setWindowMotionListener(void (*)(int, int)) const -> void = 0;
            virtual auto setWindowKeyboardListener(void (*)(unsigned char, int, int)) const -> void = 0;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
