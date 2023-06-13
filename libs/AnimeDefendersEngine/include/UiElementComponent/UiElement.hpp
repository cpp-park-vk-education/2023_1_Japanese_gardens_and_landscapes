#pragma once

#include "Component.hpp"
#include "Coords2d.hpp"

#include <array>
#include <functional>

namespace AnimeDefendersEngine {
    namespace Graphics {

        class UiElement : public Component {
         public:
            auto applyUiElementTransform() -> void;
            auto drawUiElement() -> void;
            auto checkByPointInclude(int, int) -> bool;

            auto setPosition(int, int) -> void;
            auto setWidth(int) -> void;
            auto setHeidth(int) -> void;
            auto setEventOnClick(std::function<void(int, int, int)>) -> void;

         private:
            Math::Coords2d<int> m_position;
            int m_width;
            int m_heidth;
            std::function<void(int, int, int)> m_eventOnClick;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
