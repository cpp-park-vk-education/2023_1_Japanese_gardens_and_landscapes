#pragma once

#include "ITransposeMathWrapper.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class TransposeMathWrapper : public ITransposeMathWrapper {
         public:
            auto applyTransposeMatrix(const Transpose&) const -> void override;
            auto dropLastMatrix() const -> void override;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
