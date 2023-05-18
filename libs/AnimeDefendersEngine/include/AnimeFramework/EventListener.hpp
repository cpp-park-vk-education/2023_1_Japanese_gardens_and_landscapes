#pragma once

namespace AnimeDefendersEngine {
    class IEventListener {
        virtual auto onKeyDown(int key) -> void = 0;
        virtual auto onKeyUp(int key) -> void = 0;
        virtual auto onMouseButtonDown(int button) -> void = 0;
        virtual auto onMouseButtonUp(int button) -> void = 0;
    };
}  // namespace AnimeDefendersEngine