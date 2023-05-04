#pragma ones

#include <array>
#include <functional>

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

 private:
    std::array<int, 2> m_position;
    int m_width;
    int m_heidth;
    std::function<void(void*)> m_eventOnClick;
};
