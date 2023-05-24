#pragma once

#include "Color.hpp"
#include "FileSystem.hpp"
#include "Matrix2d.hpp"
#include "Texture.hpp"

namespace AnimeDefendersEngine::Graphics {

    class IDrawTextureWrapper {
     public:
        [[nodiscard]] virtual auto loadTexture(const FileSystem::Image&) const noexcept -> Texture = 0;
        virtual auto drawTexture(const Texture&) const noexcept -> void = 0;
    };

}  // namespace AnimeDefendersEngine::Graphics
