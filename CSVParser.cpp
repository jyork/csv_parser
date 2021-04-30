#include <iostream>

#include "CSVParser.h"

enum class State
{
    Unquoted,
    Quoted,
    DoubleQuouted
};

const char DOUBLEQUOTE = '"';

CSVParser::CSVParser(char delimeter, bool throw_if_bad)
    : m_delimeter(delimeter), m_throw_on_bad_line(throw_if_bad)
{
}

std::vector<std::string> CSVParser::ReadRow(const std::string& line)
{
    State state = State::Unquoted;
    std::vector<std::string> data = { "" };
    size_t index = 0;
    for (char ch : line)
    {
        switch (state)
        {
        case State::Unquoted:
            if (ch == m_delimeter)
            {
                data.push_back("");
                index++;
            }
            else if (DOUBLEQUOTE == ch)
            {
                state = State::Quoted;
            }
            else
            {
                data[index].push_back(ch);
            }
            break;
        case State::Quoted:
            if (DOUBLEQUOTE == ch)
            {
                state = State::DoubleQuouted;

            }
            else
            {
                data[index].push_back(ch);
            }
            break;
        case State::DoubleQuouted:
            if (ch == m_delimeter)
            {
                data.push_back("");
                index++;
                state = State::Unquoted;
            }
            else if (DOUBLEQUOTE == ch)
            {
                data[index].push_back('"');
                state = State::Quoted;
            }
            else
            {
                state = State::Unquoted;
            }
            break;
        }
    }
    if (m_throw_on_bad_line && (State::Quoted == state))
    {
        throw std::runtime_error("CSV line contains mismatched quotes");
    }
    return data;
}
