#pragma ones

#include "UiColorElement.hpp"
#include "UiElementSystem.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class UiColorElementSystem : public UiElementSystem {
         public:
            static auto applyUiElementTransform(const UiColorElement&) -> void const;
            static auto drawUiElement(const UiColorElement&) -> void const;
            static auto checkByPointInclude(const UiColorElement&, int, int) -> bool const;

         private:
            UiColorElementSystem();
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
