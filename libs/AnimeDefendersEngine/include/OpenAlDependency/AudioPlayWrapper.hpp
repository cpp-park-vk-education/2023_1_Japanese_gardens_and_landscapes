#pragma once

#include "FileSystem.hpp"

namespace AnimeDefendersEngine {
    namespace Audio {

        class IAudioPlayWrapper {
         public:
            virtual auto playSound(const FileSystem::AudioTrack& track) -> void = 0;
        };

        class AudioPlayWrapper : public IAudioPlayWrapper {
         public:
            auto playSound(const FileSystem::AudioTrack& track) -> void;
        };

    }  // namespace Audio
}  // namespace AnimeDefendersEngine
