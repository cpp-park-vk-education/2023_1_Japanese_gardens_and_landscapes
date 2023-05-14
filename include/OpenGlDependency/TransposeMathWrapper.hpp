#pragma once

#include "ITransposeMathWrapper.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class TransposeMathWrapper : public ITransposeMathWrapper {
            auto initialIdentityMatrix() -> void const override;
            auto applyTransposeMatrix(const Transpose&) -> void const override;
            auto dropLastMatrix() -> void const override;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
