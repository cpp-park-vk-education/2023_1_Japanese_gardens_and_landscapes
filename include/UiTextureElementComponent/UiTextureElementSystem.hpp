#pragma ones

#include "UiElementSystem.hpp"
#include "UiTextureElement.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class UiTextureElementSystem : public UiElementSystem {
         public:
            static auto applyUiElementTransform(const UiTextureElement&) -> void const;
            static auto drawUiElement(const UiTextureElement&) -> void const;
            static auto checkByPointInclude(const UiTextureElement&, int, int) -> bool const;

         private:
            UiTextureElementSystem();
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
