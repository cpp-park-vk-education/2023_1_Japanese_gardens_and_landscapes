#pragma once

#include "IWindow.hpp"
#include "Scene.hpp"

#include <memory>

namespace AnimeDefendersEngine::Graphics {

    class Renderer {
     public:
        explicit Renderer(std::shared_ptr<IWindow>) noexcept;

        auto renderObjects(Scene&) -> void;

     private:
        std::shared_ptr<IWindow> m_window;
    };

}  // namespace AnimeDefendersEngine::Graphics
