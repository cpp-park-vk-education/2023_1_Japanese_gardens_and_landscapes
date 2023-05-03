#pragma once

#include "ITrasposeMathWrapper.hpp"

class TransposeMathWrapper : public ITransposeMathWrapper {
  auto initialIdentityMatrix() -> void override;
  auto applyTransposeMatrix(Transpose *) -> void override;
  auto dropLastMatrix() -> void override;
};
