#pragma once

#include "FileSystem.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class IDrawTextureWrapper {
         public:
            virtual auto drawTexture(const FileSystem::Image&) -> void = 0;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
