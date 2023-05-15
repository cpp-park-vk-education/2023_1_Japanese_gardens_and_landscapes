#pragma once

#include <cstddef>

namespace AnimeDefendersEngine {

    template <typename T>
    class MemoryMaster {
     public:
        using size_type = std::size_t;

     public:
        auto allocate(size_type size) -> T* {}

        void deallocate(T*, size_type size) {}
    };

}  // namespace AnimeDefendersEngine
