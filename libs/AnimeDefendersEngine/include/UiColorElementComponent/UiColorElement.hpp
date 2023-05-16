#pragma once

#include "Color.hpp"
#include "Coords2d.hpp"
#include "UiElement.hpp"

#include <array>
#include <functional>

namespace AnimeDefendersEngine {
    namespace Graphics {

        class UiColorElement : public UiElement {
         public:
            auto applyUiElementTransform() -> void;
            auto drawUiElement() -> void;
            auto checkByPointInclude(int, int) -> bool;

            auto setPosition(int, int) -> void;
            auto setWidth(int) -> void;
            auto setHeidth(int) -> void;
            auto setEventOnClick(std::function<void(int, int, int)>) -> void;
            auto setColor(Color) -> void;

         private:
            Math::Coords2d<int> m_position;
            int m_width;
            int m_heidth;
            std::function<void(int, int, int)> m_eventOnClick;
            Color m_color;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
