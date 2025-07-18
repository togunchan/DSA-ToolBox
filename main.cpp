#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "src/sort/quickSort.hpp"
#include "src/sort/mergeSort.hpp"
#include "utils/input_parser.hpp"
#include "src/graph/graph.hpp"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage:\n"
                  << "  dsa-toolbox sort --algo quicksort|mergesort --input file\n"
                  << "  dsa-toolbox benchmark --input file\n";
        return 1;
    }

    std::string action = argv[1];
    if (action == "sort")
    {
        if (argc < 6 || std::string(argv[2]) != "--algo" || std::string(argv[4]) != "--input")
        {
            std::cerr << "Usage: dsa-toolbox sort --algo quicksort|mergesort --input file\n";
            return 1;
        }
        std::string algo = argv[3];
        std::string inputFile = argv[5];
        std::vector<int> data = readIntFile(inputFile);

        if (data.empty())
        {
            std::cerr << "Error: Input file is empty or not found.\n";
            return 1;
        }

        std::cout << "-----------------------------" << std::endl;
        std::cout << "Before " << algo << " : ";
        for (int num : data)
            std::cout << num << " ";
        std::cout << "\n";

        if (algo == "quicksort")
        {
            quickSort(data, 0, data.size() - 1);
            std::cout << "-----------------------------" << std::endl;
        }
        else if (algo == "mergesort")
        {
            mergeSort(data, 0, data.size() - 1);
            std::cout << "-----------------------------" << std::endl;
        }
        else
        {
            std::cerr << "Unknown algorithm: " << algo << "\n";
            return 1;
        }

        std::cout << "After " << algo << " : ";
        for (int num : data)
            std::cout << num << " ";
        std::cout << "\n";
        std::cout << "-----------------------------" << std::endl;
    }
    else if (action == "benchmark-sort")
    {
        if (argc < 4 || std::string(argv[2]) != "--input")
        {
            std::cerr << "Usage: dsa-toolbox benchmark --input file\n";
            return 1;
        }

        std::string inputFile = argv[3];
        std::vector<int> data = readIntFile(inputFile);

        if (data.empty())
        {
            std::cerr << "Error: Input file is empty or not found.\n";
            return 1;
        }

        // QuickSort
        std::vector<int> quickData = data;
        auto startQuick = std::chrono::high_resolution_clock::now();
        quickSort(quickData, 0, quickData.size() - 1);
        auto endQuick = std::chrono::high_resolution_clock::now();
        auto durationQuick = std::chrono::duration_cast<std::chrono::microseconds>(endQuick - startQuick);
        std::cout << "QuickSort took: " << durationQuick.count() << " microseconds\n";

        // MergeSort
        std::vector<int> mergeData = data;
        auto startMerge = std::chrono::high_resolution_clock::now();
        mergeSort(mergeData, 0, mergeData.size() - 1);
        auto endMerge = std::chrono::high_resolution_clock::now();
        auto durationMerge = std::chrono::duration_cast<std::chrono::microseconds>(endMerge - startMerge);
        std::cout << "MergeSort took: " << durationMerge.count() << " microseconds\n";
    }
    else if (action == "benchmark-graph")
    {
        if (argc < 4 || std::string(argv[2]) != "--input")
        {
            std::cerr << "Usage: dsa-toolbox benchmark-graph --input file\n";
            return 1;
        }

        std::string inputFile = argv[3];

        Graph g;
        g.loadFromFile(inputFile);

        // DFS Benchmark
        auto startDFS = std::chrono::high_resolution_clock::now();
        g.dfs(0);
        auto endDFS = std::chrono::high_resolution_clock::now();
        auto durationDFS = std::chrono::duration_cast<std::chrono::microseconds>(endDFS - startDFS);
        std::cout << "DFS traversal took: " << durationDFS.count() << " microseconds\n";

        // BFS Benchmark
        auto startBFS = std::chrono::high_resolution_clock::now();
        g.bfs(0);
        auto endBFS = std::chrono::high_resolution_clock::now();
        auto durationBFS = std::chrono::duration_cast<std::chrono::microseconds>(endBFS - startBFS);
        std::cout << "BFS traversal took: " << durationBFS.count() << " microseconds\n";
    }
    else if (action == "graph")
    {
        //./dsa_toolbox graph --algo dfs --input ../data/graph.txt
        if (argc < 6 || std::string(argv[2]) != "--algo" || std::string(argv[4]) != "--input")
        {
            std::cerr << "Usage: dsa-toolbox graph --algo dfs --input file\n";
            return 1;
        }
        std::string algo = argv[3];
        std::string inputFile = argv[5];

        if (algo == "dfs")
        {
            Graph g;
            g.loadFromFile(inputFile);
            std::cout << "DFS traversal: ";
            g.dfs(0);
            std::cout << "\n";
            g.printAdjList();
        }
        else if (algo == "bfs")
        {
            Graph g;
            g.loadFromFile(inputFile);
            std::cout << "BFS traversal: ";
            g.bfs(0);
            std::cout << "\n";
            g.printAdjList();
        }
        else
        {
            std::cerr << "Unknown graph algorithm: " << algo << "\n";
            return 1;
        }
    }
    else
    {
        std::cerr << "Invalid command. Use 'sort' or 'benchmark or graph'.\n";
        return 1;
    }
    return 0;
}