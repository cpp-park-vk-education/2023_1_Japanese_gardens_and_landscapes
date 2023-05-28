#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace AnimeDefendersEngine {

    namespace FileSystem {

        class TableReader {
         public:
            using valueType = std::string;
            using keyType = std::string;

         public:
            explicit TableReader(std::unique_ptr<std::istream> dataStream, char separator = ' ');

            [[nodiscard]] auto operator[](const keyType& key) -> valueType&;
            [[nodiscard]] auto operator[](const keyType& key) const -> const valueType&;

            [[nodiscard]] auto endOfTable() const -> bool;

            auto readNewRow() -> void;

         private:
            [[nodiscard]] auto isValuesReadable() const -> bool;

         private:
            std::unique_ptr<std::istream> m_dataStream;
            std::unordered_map<keyType, valueType> m_lineValues;
            std::vector<keyType> m_columnsNames;

         private:
            const char m_wordsInRowSeparator = ' ';
        };

        [[nodiscard]] auto splitString(const std::string& str, char separator) -> std::vector<std::string>;

    }  // namespace FileSystem

}  // namespace AnimeDefendersEngine
