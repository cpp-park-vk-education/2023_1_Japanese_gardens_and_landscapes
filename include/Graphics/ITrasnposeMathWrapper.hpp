#pragma ones

#include "Transpose.hpp"

class ITransposeMathWrapper {
public:
  virtual auto initialIdentityMatrix() -> void = 0;
  virtual auto applyTransposeMatrix(Transpose *) -> void = 0;
  virtual auto dropLastMatrix() -> void = 0;
};
