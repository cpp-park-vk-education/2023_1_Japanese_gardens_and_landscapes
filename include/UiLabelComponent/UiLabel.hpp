#pragma ones

#include "Color.hpp"
#include "Coords2d.hpp"
#include "UiElement.hpp"

#include <array>
#include <functional>
#include <string>

namespace AnimeDefendersEngine {
    namespace Graphics {

        class UiLabel : public UiElement {
         public:
            auto applyUiElementTransform() -> void const;
            auto drawUiElement() -> void const;
            auto checkByPointInclude(int, int) -> bool const;

            auto setPosition(int, int) -> void;
            auto setWidth(int) -> void;
            auto setHeidth(int) -> void;
            auto setEventOnClick(std::function<void(int, int, int)>) -> void;
            auto setTextContent(const std::string&) -> void;
            auto setTextColor(Color) -> void;

         private:
            Math::Coords2d<int> m_position;
            int m_width;
            int m_heidth;
            std::function<void(int, int, int)> m_eventOnClick;
            const std::string& textContent;
            Color m_textColor;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
