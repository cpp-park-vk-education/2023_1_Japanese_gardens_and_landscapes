#pragma once

#include "Component.hpp"
#include "FileSystem.hpp"

namespace AnimeDefendersEngine {
    namespace Audio {

        class AudioSource : public Component {
         public:
            auto playAudio() -> void;

         private:
            FileSystem::Audio audioSource;
        };

    }  // namespace Audio
}  // namespace AnimeDefendersEngine
