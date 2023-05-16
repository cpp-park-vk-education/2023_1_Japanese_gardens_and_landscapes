#pragma once

#include "IWindow.hpp"
#include "Scene.hpp"

#include <memory>

namespace AnimeDefendersEngine {
    namespace Graphics {

        class Renderer {
         public:
            Renderer(std::shared_ptr<IWindow>);
            auto renderObjects(const Scene&) -> void;

         private:
            std::shared_ptr<IWindow> m_window;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
