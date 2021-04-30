#pragma once

#include <string>
#include <vector>

class CSVParser
{
    char m_delimeter;
    bool m_throw_on_bad_line;
public:
    CSVParser(char delimeter = ',', bool throw_if_bad = false);
    std::vector<std::string> ReadRow(const std::string& line);
};