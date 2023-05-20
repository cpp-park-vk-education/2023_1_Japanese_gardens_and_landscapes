#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace AnimeDefendersEngine {
    class TableReader {
     public:
        using valueType = std::string;
        using keyType = std::string;

     public:
        explicit TableReader(std::unique_ptr<std::istream>&& dataStream, const char separator = ' ');

        [[nodiscard]] auto operator[](const keyType& key) -> valueType&;

        [[nodiscard]] auto operator[](const keyType& key) const -> valueType;

        [[nodiscard]] auto endOfStream() const -> bool;

        auto readNewRow() -> void;

     private:
        [[nodiscard]] auto is_ValuesReadable() const -> bool;

     private:
        std::unique_ptr<std::istream> m_dataStream;
        std::unordered_map<keyType, valueType> m_lineValues;
        std::vector<keyType> m_columnsNames;

     private:
        const char m_wordsInRowSeparator = ' ';
    };

}  // namespace AnimeDefendersEngine