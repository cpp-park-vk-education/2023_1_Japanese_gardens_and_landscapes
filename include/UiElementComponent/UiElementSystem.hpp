#pragma ones

#include "ISystem.hpp"
#include "UiElement.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class UiElementSystem : public ISystem {
         public:
            static auto applyUiElementTransform(const UiElement&) -> void const;
            static auto drawUiElement(const UiElement&) -> void const;
            static auto checkByPointInclude(const UiElement&, int, int) -> bool const;

         private:
            UiElementSystem();
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
