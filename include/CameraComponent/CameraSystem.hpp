#pragma ones

#include "Camera.hpp"
#include "System.hpp"

namespace AnimeDefendersEngine {

    class CameraSystem : public System {
     public:
        static auto determineNewCameraTranspose(Camera*) -> void const;
        static auto applyCameraView(Camera*) -> void const;

     private:
        CameraSystem();
    };

}  // namespace AnimeDefendersEngine
