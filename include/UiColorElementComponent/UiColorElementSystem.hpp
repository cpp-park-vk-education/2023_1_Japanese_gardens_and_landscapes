#pragma ones

#include "UiColorElement.hpp"
#include "UiElementSystem.hpp"

namespace AnimeDefendersEngine {

    class UiColorElementSystem : public UiElementSystem {
     public:
        static auto applyUiElementTransform(UiColorElement*) -> void const;
        static auto drawUiElement(UiColorElement*) -> void const;
        static auto checkByPointInclude(UiColorElement*, int, int) -> bool const;

     private:
        UiColorElementSystem();
    };

}  // namespace AnimeDefendersEngine
