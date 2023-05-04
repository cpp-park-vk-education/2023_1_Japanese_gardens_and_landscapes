#pragma once

#include "IWindow.hpp"
#include "Scene.hpp"

#include <memory>

namespace AnimeDefendersEngine {

    class Renderer {
     public:
        Renderer();
        auto renderObjects(Scene&) -> void const;

     private:
        std::unique_ptr<IWindow> m_window;
    };

}  // namespace AnimeDefendersEngine
