#pragma ones

#include "Transpose.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class ITransposeMathWrapper {
         public:
            virtual auto initialIdentityMatrix() -> void const = 0;
            virtual auto applyTransposeMatrix(Transform&) -> void const = 0;
            virtual auto dropLastMatrix() -> void const = 0;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
