#pragma once

namespace AnimeDefendersEngine {
    namespace Audio {
        class IAudioPlayWrapper {
         public:
            virtual auto playSound(const AudioTrack& track) -> void = 0;
        };
        class AudioPlayWrapper: public IAudioPlayWrapper {
            public:
            auto playSound(const AudioTrack& track) -> void;
        };
    }  // namespace Audio
}  // namespace AnimeDefendersEngine