#include "graph.hpp"
#include <fstream>
#include <iostream>

void Graph::addEdge(int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void Graph::printAdjList() const
{
    for (const auto &entry : adjList)
    {
        int node = entry.first;
        const std::vector<int> &neighbors = entry.second;
        std::cout << "Node " << node << ": ";
        for (int neighbor : neighbors)
        {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::loadFromFile(std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    int nodeCount, edgeCount;
    file >> nodeCount >> edgeCount;

    for (int i = 0; i < edgeCount; i++)
    {
        int u, v;
        file >> u >> v;
        addEdge(u, v);
    }

    file.close();
}

void Graph::dfs(int startNode)
{
    std::unordered_map<int, bool> visited;
    dfsUtil(startNode, visited);
}

void Graph::dfsUtil(int node, std::unordered_map<int, bool> &visited)
{
    visited[node] = true;
    std::cout << node << " ";
    for (int neighbor : adjList[node])
    {
        if (!visited[neighbor])
        {
            dfsUtil(neighbor, visited);
        }
    }
}

void Graph::bfs(int startNode)
{
    std::unordered_map<int, bool> visited;
    // std::vector<bool> visited(adjList.size(), false);
    std::queue<int> q;
    q.push(startNode);
    visited[startNode] = true;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        std::cout << current << " ";
        for (int neighbor : adjList[current])
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}
