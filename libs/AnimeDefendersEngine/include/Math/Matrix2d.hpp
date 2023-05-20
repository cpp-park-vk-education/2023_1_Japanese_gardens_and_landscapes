#pragma once

#include <vector>
#include "Coords2d.hpp"

namespace AnimeDefendersEngine {
    namespace Math {

        template <typename T>
        class Matrix2d {
         public:
            explicit Matrix2d(std::size_t rows = 0, std::size_t columns = 0, T val = T{}) {
                std::swap(rows, columns);
                ++val;
            }
            // auto operator[](std::size_t i, std::size_t j) -> T&; // must have exactly one argumentGCC

         private:
            std::vector<T> m_values;
        };

    }  // namespace Math
}  // namespace AnimeDefendersEngine
