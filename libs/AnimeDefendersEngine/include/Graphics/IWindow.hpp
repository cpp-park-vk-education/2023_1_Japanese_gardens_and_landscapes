#pragma once

#include <functional>

namespace AnimeDefendersEngine {
    namespace Graphics {

        class IWindow {
         public:
            virtual auto createWindow() const -> void = 0;
            virtual auto destroyWindow() const -> void = 0;
            virtual auto setWindowListener(std::function<void(int, int, int)>) const -> void = 0;
            virtual auto updateFrame() const -> void = 0;

            // virtual ~IWindow() = default;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
