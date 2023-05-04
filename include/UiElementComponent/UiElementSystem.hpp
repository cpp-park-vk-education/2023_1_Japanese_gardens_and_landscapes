#pragma ones

#include "ISystem.hpp"
#include "UiElement.hpp"

namespace AnimeDefendersEngine {

    class UiElementSystem : public ISystem {
     public:
        static auto applyUiElementTransform(UiElement*) -> void const;
        static auto drawUiElement(UiElement*) -> void const;
        static auto checkByPointInclude(UiElement*, int, int) -> bool const;

     private:
        UiElementSystem();
    };

}  // namespace AnimeDefendersEngine
