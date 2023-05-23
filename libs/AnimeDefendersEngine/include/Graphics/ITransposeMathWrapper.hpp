#pragma once

#include "Transpose.hpp"

namespace AnimeDefendersEngine::Graphics {

    class ITransposeMathWrapper {
     public:
        virtual auto applyTransposeMatrix(const Math::Transpose&) const noexcept -> void = 0;
        virtual auto dropLastMatrix() const noexcept -> void = 0;
    };

}  // namespace AnimeDefendersEngine::Graphics
