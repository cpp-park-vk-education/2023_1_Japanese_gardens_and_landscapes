#pragma once

#include "Coords2d.hpp"

#include <stdexcept>
#include <ranges>
#include <vector>

namespace AnimeDefendersEngine {
    namespace Math {

        template <Number T>
        class Matrix2d {
         public:
            explicit Matrix2d(std::size_t rows = 0, std::size_t columns = 0, T val = T{})
                : m_rows{rows}, m_columns{m_columns}, m_values(rows * columns, val) {}

            Matrix2d(std::size_t rows, std::size_t columns, const std::vector<T>& values) : m_rows{rows}, m_columns{columns} {
                if (m_rows * m_columns != values.size()) {
                    throw std::invalid_argument{
                        "While constructing matrix got array of elements which does not work with numer of rows and columns"};
                }

                m_values = values;
            }

            /**
             * @brief Return element reference of matrix by it`s index
             *
             * @param i Row index. Starting from 0.
             * @param j Column index. Starting from 0.
             */
            [[nodiscard]] auto getElement(const std::size_t i, const std::size_t j) -> T& {
                if (i >= m_rows || j >= m_columns) {
                    throw std::out_of_range{"Indexing Matrix2d"};
                }
                return m_values[m_getIndex(i, j)];
            }

            /**
             * @brief Return copy of element of matrix by it`s index
             *
             * @param i Row index. Starting from 0.
             * @param j Column index. Starting from 0.
             *
             * @return Element copy
             */
            [[nodiscard]] auto getElement(const std::size_t i, const std::size_t j) const -> T {
                if (i >= m_rows || j >= m_columns) {
                    throw std::out_of_range{"Indexing Matrix2d"};
                }
                return m_values[m_getIndex(i, j)];
            }

            // auto operator[](std::size_t i, std::size_t j) -> T&; // must have exactly one argumentGCC


            auto begin() -> 
         private:
            [[nodiscard]] auto m_getIndex(const std::size_t i, const std::size_t j) const noexcept -> std::size_t {
                return i + j * m_columns;
            }

            std::size_t m_rows{};
            std::size_t m_columns{};
            std::vector<T> m_values;
        };

    }  // namespace Math
}  // namespace AnimeDefendersEngine
