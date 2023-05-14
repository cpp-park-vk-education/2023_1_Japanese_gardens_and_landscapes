#pragma ones

#include "UiElementSystem.hpp"
#include "UiLabel.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class UiLabelSystem : public UiElementSystem {
         public:
            static auto applyUiElementTransform(const UiLabel&) -> void const;
            static auto drawUiElement(const UiLabel&) -> void const;
            static auto checkByPointInclude(const UiLabel&, int, int) -> bool const;

         private:
            UiLabelSystem();
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
