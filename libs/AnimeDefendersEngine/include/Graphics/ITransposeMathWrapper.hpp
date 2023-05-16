#pragma once

#include "Transform.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class ITransposeMathWrapper {
         public:
            virtual auto initialIdentityMatrix() -> void = 0;
            virtual auto applyTransposeMatrix(const Transform&) -> void = 0;
            virtual auto dropLastMatrix() -> void = 0;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
