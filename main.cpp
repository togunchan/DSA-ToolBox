#include <iostream>
#include <string>
#include <vector>
#include "src/sort/quickSort.hpp"

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        std::cerr << "Usage: dsa-toolbox sort --algo quick\n";
        return 1;
    }

    std::string action = argv[1];
    std::string flag = argv[2];
    std::string algo = argv[3];

    if (action == "sort" || flag == "--algo")
    {
        if (algo == "quicksort")
        {
            std::vector<int> data = {9, 4, 7, 3, 1, 6};

            std::cout << "Before sorting: ";
            for (int num : data)
                std::cout << num << " ";
            std::cout << "\n";

            quickSort(data, 0, data.size() - 1);

            std::cout << "After sorting: ";
            for (int num : data)
                std::cout << num << " ";
            std::cout << "\n";
        }
        else
        {
            std::cerr << "Unknown algorithm: " << algo << "\n";
            return 1;
        }
    }
    else
    {
        std::cerr << "Invalid usage. Expected: sort --algo quicksort\n";
        return 1;
    }

    return 0;
}