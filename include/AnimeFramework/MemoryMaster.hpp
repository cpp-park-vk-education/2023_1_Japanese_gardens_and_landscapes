#pragma once

#include <cstddef>

namespace AnimeDefendersEngine {

    class MemoryMaster {
     public:
        using size_type = std::size_t;

     public:
        template <typename T>
        auto allocate(size_type size) -> T*;

        template <typename T>
        void deallocate(T*);
    };

}  // namespace AnimeDefendersEngine
