#pragma once

#include "Component.hpp"

namespace AnimeDefendersEngine {
    namespace Audio {

        class AudioSource : public Component {
         public:
            auto PlayAudio() -> void;
            private:
            //FileSystem::Audio audioSource;
        };

    }  // namespace Audio
}  // namespace AnimeDefendersEngine
