#pragma once

#include "IDrawTextureWrapper.hpp"

class DrawTextureWrapper : public IDrawTextureWrapper {
public:
  auto drawTexture(FileSystem::image &) -> void override;
};
