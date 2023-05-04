#pragma ones

#include "UiElementSystem.hpp"
#include "UiTextureElement.hpp"

namespace AnimeDefendersEngine {

    class UiTextureElementSystem : public UiElementSystem {
     public:
        static auto applyUiElementTransform(UiTextureElement*) -> void const;
        static auto drawUiElement(UiTextureElement*) -> void const;
        static auto checkByPointInclude(UiTextureElement*, int, int) -> bool const;

     private:
        UiTextureElementSystem();
    };

}  // namespace AnimeDefendersEngine
