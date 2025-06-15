#include "input_parser.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<int> readIntFile(const std::string &filename)
{
    std::ifstream file(filename);
    std::vector<int> result;

    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return result;
    }

    int number;
    while (file >> number)
    {
        result.push_back(number);
    }

    return result;
}