#pragma ones

#include "FileSystem.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class IDrawTextureWrapper {
         public:
            virtual auto drawTexture(Image&) -> void const = 0;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
