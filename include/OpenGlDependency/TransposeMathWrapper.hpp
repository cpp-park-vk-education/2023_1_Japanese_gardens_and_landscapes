#pragma once

#include "ITransposeMathWrapper.hpp"

namespace AnimeDefendersEngine {

    class TransposeMathWrapper : public ITransposeMathWrapper {
        auto initialIdentityMatrix() -> void const override;
        auto applyTransposeMatrix(Transpose*) -> void const override;
        auto dropLastMatrix() -> void const override;
    };

}  // namespace AnimeDefendersEngine
