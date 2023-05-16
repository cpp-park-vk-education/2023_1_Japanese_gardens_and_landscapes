#pragma once

#include <vector>

namespace AnimeDefendersEngine {
    namespace Math {

        template <typename T>
        class Vector2 {
         public:
            explicit Vector2(T val1 = T{}, T val2 = T{});
            auto operator[](std::size_t i) -> T&;

         private:
            std::vector<T> m_values;
        };

    }  // namespace Math
}  // namespace AnimeDefendersEngine
