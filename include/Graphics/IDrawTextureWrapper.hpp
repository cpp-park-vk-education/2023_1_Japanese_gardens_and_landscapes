#pragma ones

#include "FileSystem.hpp"

namespace AnimeDefendersEngine {

    class IDrawTextureWrapper {
     public:
        virtual auto drawTexture(Image&) -> void const = 0;
    };

}  // namespace AnimeDefendersEngine
