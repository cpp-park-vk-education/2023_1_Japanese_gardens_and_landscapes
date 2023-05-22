#pragma once

#include "ITransposeMathWrapper.hpp"

namespace AnimeDefendersEngine::Graphics {

    class TransposeMathWrapper final : public ITransposeMathWrapper {
     public:
        auto applyTransposeMatrix(const Transpose*) const -> void override;
        auto dropLastMatrix() const -> void override;
    };

}  // namespace AnimeDefendersEngine::Graphics
