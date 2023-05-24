#include "TableReader.hpp"

#include <algorithm>
#include <sstream>

namespace AnimeDefendersEngine::FileSystem {

    auto SplitString(const std::string& str, const char separator) -> std::vector<std::string> {
        std::vector<std::string> splittedString{};
        std::stringstream stream{str};
        while (!stream.eof()) {
            std::string token;
            std::getline(stream, token, separator);
            splittedString.push_back(token);
        }

        return splittedString;
    }

    [[nodiscard]] auto TableReader::endOfTable() const -> bool {
        return m_dataStream->eof();
    }

    void TableReader::readNewRow() {
        std::string line{};
        while (line.empty()) {
            if (m_dataStream->eof()) {
                return;
            }
            std::getline(*m_dataStream, line);
        }
        const auto splittedString = SplitString(line, m_wordsInRowSeparator);

        if (splittedString.size() != m_columnsNames.size()) {
            throw std::runtime_error{
                "Error while reading table: number of elements in "
                "row not equal to numbers of columns"};
        }

        for (std::size_t i = 0; i < splittedString.size(); ++i) {
            m_lineValues[m_columnsNames[i]] = splittedString[i];
        }
    }

    [[nodiscard]] auto TableReader::operator[](const TableReader::keyType& key) const -> const TableReader::valueType& {
        if (m_lineValues.find(key) == m_lineValues.end()) {
            throw std::runtime_error{"Element with key \"" + key + "\"  not exist"};
        }
        return m_lineValues.at(key);
    }

    [[nodiscard]] auto TableReader::operator[](const TableReader::keyType& key) -> TableReader::valueType& {
        if (m_lineValues.find(key) == m_lineValues.end()) {
            throw std::runtime_error{"Element with key \"" + key + "\" not exist"};
        }
        return m_lineValues.at(key);
    }

    TableReader::TableReader(std::unique_ptr<std::istream> dataStream, char wordsInRowSeparator)
        : m_dataStream{std::move(dataStream)}, m_wordsInRowSeparator{wordsInRowSeparator} {
        if (!m_dataStream->good() || m_dataStream->eof()) {
            throw std::runtime_error{"Unable to read table: bad stream"};
        }

        std::string line{};
        std::getline(*m_dataStream, line);

        if (line.empty()) {
            throw std::runtime_error{"Unable to read table: empty stream"};
        }

        auto splitedString = SplitString(line, m_wordsInRowSeparator);
        for (const auto& word : splitedString) {
            m_columnsNames.emplace_back(word);
        }

        readNewRow();
        if (!isValuesReadable()) {
            throw std::runtime_error{"Unable to read first table row"};
        }
    }

    [[nodiscard]] auto TableReader::isValuesReadable() const -> bool {
        auto is_tableContainsElementWithColumnName = [this](const std::string& name) { return m_lineValues.contains(name); };

        return std::ranges::all_of(m_columnsNames.cbegin(), m_columnsNames.cend(), is_tableContainsElementWithColumnName);
    }

}  // namespace AnimeDefendersEngine::FileSystem
