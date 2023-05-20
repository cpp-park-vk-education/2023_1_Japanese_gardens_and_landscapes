#pragma once

#include "Coords2d.hpp"

#include <algorithm>
#include <ranges>
#include <stdexcept>
#include <vector>

#include <iostream>

namespace AnimeDefendersEngine {
    namespace Math {

        template <typename T>
        class Matrix2d {
         public:
            explicit Matrix2d(std::size_t rows = 0, std::size_t columns = 0, T val = T{})
                : m_rows{rows}, m_columns{m_columns}, m_values(rows * columns, val) {}

            Matrix2d(std::size_t rows, std::size_t columns, std::ranges::sized_range auto values) : m_rows{rows}, m_columns{columns} {
                if (m_rows * m_columns != std::ranges::size(values)) {
                    throw std::invalid_argument{
                        "While constructing matrix got array of elements which does not work with numer of rows and columns"};
                }
                m_values.resize(m_columns * m_rows);

                std::ranges::copy(values, m_values.begin());
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

            [[nodiscard]] auto begin() -> typename std::vector<T>::iterator { return m_values.begin(); }
            [[nodiscard]] auto end() -> typename std::vector<T>::iterator { return m_values.end(); }
            [[nodiscard]] auto size() const noexcept -> std::size_t { return m_columns * m_rows; }

            [[nodiscard]] auto rows() const noexcept -> std::size_t { return m_rows; }
            [[nodiscard]] auto columns() const noexcept -> std::size_t { return m_columns; }

         private:
            [[nodiscard]] auto m_getIndex(const std::size_t i, const std::size_t j) const noexcept -> std::size_t {
                return i * m_columns + j;
            }

            std::size_t m_rows{};
            std::size_t m_columns{};
            std::vector<T> m_values;
        };

    }  // namespace Math
}  // namespace AnimeDefendersEngine
