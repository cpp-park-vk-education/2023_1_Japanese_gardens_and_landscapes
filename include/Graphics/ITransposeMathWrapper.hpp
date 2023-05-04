#pragma ones

#include "Transpose.hpp"

namespace AnimeDefendersEngine {

    class ITransposeMathWrapper {
     public:
        virtual auto initialIdentityMatrix() -> void const = 0;
        virtual auto applyTransposeMatrix(Transpose*) -> void const = 0;
        virtual auto dropLastMatrix() -> void const = 0;
    };

}  // namespace AnimeDefendersEngine
