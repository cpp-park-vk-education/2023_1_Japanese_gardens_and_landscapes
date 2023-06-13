#pragma once

#include "FileSystem.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        struct Texture {
            const FileSystem::Image& image;
            int width;
            int heidth;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
