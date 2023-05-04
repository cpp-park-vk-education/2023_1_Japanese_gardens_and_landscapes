#pragma ones

#include "UiElementSystem.hpp"
#include "UiLabel.hpp"

namespace AnimeDefendersEngine {

    class UiLabelSystem : public UiElementSystem {
     public:
        static auto applyUiElementTransform(UiLabel*) -> void const;
        static auto drawUiElement(UiLabel*) -> void const;
        static auto checkByPointInclude(UiLabel*, int, int) -> bool const;

     private:
        UiLabelSystem();
    };

}  // namespace AnimeDefendersEngine
