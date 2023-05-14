#pragma ones

namespace AnimeDefendersEngine {
    namespace Math {

        template <class T>
        class Coords2d {
         public:
            explicit Coords2d(T x, T y);
            auto getX() const -> T&;
            auto getY() const -> T&;

         private:
            T m_xCoord;
            T m_yCoord;
        };

    }  // namespace Math
}  // namespace AnimeDefendersEngine
