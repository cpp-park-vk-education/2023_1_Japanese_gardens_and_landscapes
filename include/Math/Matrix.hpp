#pragma once

#include <vector>

namespace AnimeDefendersEngine {
    namespace Math {
        template <typename T>
        class Matrix2d {
         public:
            explicit Matrix2d(std::size_t rows = 0, std::size_t columns = 0, T val = T{}) {}
            auto operator[](std::size_t i, size_t j) -> T& {}

         private:
            std::vector<T> m_values;
        };
    }  // namespace Math
}  // namespace AnimeDefendersEngine