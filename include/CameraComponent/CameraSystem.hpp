#pragma ones

#include "Camera.hpp"
#include "System.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class CameraSystem : public System {
         public:
            static auto determineNewCameraTranspose(const Camera&) -> void const;
            static auto applyCameraView(const Camera&) -> void const;

         private:
            CameraSystem();
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
