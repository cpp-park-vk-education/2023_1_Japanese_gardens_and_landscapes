#pragma ones

#include "FileSystem.hpp"

class IDrawTextureWrapper {
public:
  virtual auto drawTexture(FileSystem::image &) -> void = 0;
};
