#pragma once

#include "FileSystem.hpp"
#include "IDrawTextureWrapper.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class DrawTextureWrapper : public IDrawTextureWrapper {
         public:
            auto drawTexture(const FileSystem::Image&) -> void override;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
