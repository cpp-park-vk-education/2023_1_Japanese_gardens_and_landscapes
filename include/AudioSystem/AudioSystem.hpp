#pragma once

#include "AudioSource.hpp"
#include "ISystem.hpp"

namespace AnimeDefendersEngine {
    namespace Audio {

        class AudioSystem : public ISystem {
         public:
            auto playAudio(AudioSource*) -> void;
        };

    }  // namespace Audio
}  // namespace AnimeDefendersEngine
