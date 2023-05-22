#pragma once

#include "Transpose.hpp"

namespace AnimeDefendersEngine::Graphics {

    class ITransposeMathWrapper {
     public:
        virtual auto applyTransposeMatrix(const Transpose*) const -> void = 0;
        virtual auto dropLastMatrix() const -> void = 0;
    };

}  // namespace AnimeDefendersEngine::Graphics
