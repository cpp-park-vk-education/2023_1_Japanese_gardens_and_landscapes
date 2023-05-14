#pragma once

#include "IWindow.hpp"
#include "Scene.hpp"

#include <memory>

namespace AnimeDefendersEngine {
    namespace Graphics {

        class Renderer {
         public:
            Renderer();
            auto renderObjects(Scene&) -> void const;

         private:
            std::unique_ptr<IWindow> m_window;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
