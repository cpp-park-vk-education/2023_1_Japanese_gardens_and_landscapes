#pragma ones

#include <array>
#include <functional>
#include <string>

#include "Component.hpp"

class UiElement : public Component {
 public:
    auto applyUiElementTransform() -> void const;
    auto drawUiElement() -> void const;
    auto checkByPointInclude(int, int) -> bool const;

    auto setPosition(int, int) -> void;
    auto setWidth(int) -> void;
    auto setHeidth(int) -> void;
    auto setEventOnClick(std::function<void(void*)>) -> void;
    auto setTextContent(const std::string&) -> void;
    auto setTextColor(Color) -> void;
    auto setTextSize(int) -> void;

 private:
    std::array<int, 2> m_position;
    int m_width;
    int m_heidth;
    std::function<void(void*)> m_eventOnClick;
    const std::string& textContent;
    Color m_textColor;
    int m_textSize;
};
