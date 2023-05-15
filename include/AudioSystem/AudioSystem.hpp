#pragma once

#include "ISystem.hpp"

namespace AnimeDefendersEngine {
    namespace Audio {

        class AudioSystem : public ISystem {
         public:
            auto playAudio(AudioSource* audioSource) -> void;
        };

    }  // namespace Audio
}  // namespace AnimeDefendersEngine
