#pragma once

#include <string>
#include <unordered_map>
#include <vector>

/**
 * @brief Represents a graph using an adjacency list.
 *
 * This class provides basic functionalities for managing a graph,
 * including adding edges, loading from a file, and performing DFS traversal.
 */
class Graph
{
public:
    /**
     * @brief Adds an edge between two nodes in the graph.
     *
     * This function creates a connection between nodes `u` and `v`,
     * making the graph undirected by adding edges in both directions.
     *
     * @param u The first node.
     * @param v The second node.
     */
    void addEdge(int u, int v);

    /**
     * @brief Loads graph data from a file.
     *
     * Reads edge connections from the given file and adds them to the graph.
     * The file format should contain pairs of integers representing edges.
     *
     * @param filename Path to the file containing graph data.
     */
    void loadFromFile(std::string &filename);

    /**
     * @brief Performs Depth-First Search (DFS) traversal from a given node.
     *
     * This function starts a DFS traversal from the given node, visiting
     * all reachable nodes recursively. It utilizes a visited tracking
     * mechanism to prevent revisiting nodes and ensure correct traversal.
     *
     * @param startNode The node from which DFS traversal begins.
     *
     * @note This function typically relies on an internal helper function (dfsUtil)
     *       for recursive traversal. It ensures that all connected components
     *       of the graph are explored efficiently.
     */
    void dfs(int startNode);

    /**
     * @brief Prints the adjacency list representation of the graph.
     *
     * This function iterates through each node in the graph and displays
     * its connected neighbors. Useful for debugging and understanding
     * the graph structure.
     *
     * @note Since this function is marked as `const`, it does not modify
     *       the graph in any way.
     */
    void printAdjList() const;

    /**
     * @brief Helper function for Depth-First Search (DFS).
     *
     * This recursive function traverses the graph using DFS, marking visited nodes
     * and printing them to the console. It ensures that each node is visited only once.
     *
     * @param node The current node being explored.
     * @param visited Reference to the map tracking visited nodes to prevent redundant visits.
     */
    void dfsUtil(int node, std::unordered_map<int, bool> &visited);

private:
    /**
     * @brief Adjacency list representing graph connections.
     *
     * Each key is a node, and the corresponding value is a vector
     * of adjacent nodes.
     */
    std::unordered_map<int, std::vector<int>> adjList;

    /**
     * @brief Tracks visited nodes during traversal.
     *
     * This unordered map helps prevent cycles and redundant visits
     * in DFS exploration.
     */
    std::unordered_map<int, bool> visited;
};
