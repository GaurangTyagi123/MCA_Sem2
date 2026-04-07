#include <iostream>
#include <vector>
#include <unordered_map>
#include <forward_list>
#include <sstream>
#include <fstream>

struct customComparator
{
    bool operator()(const std::pair<std::string, int> &p1, const std::pair<std::string, int> &p2)
    {
        return p1.second > p2.second;
    }
};
std::unordered_map<std::string, std::forward_list<std::pair<std::string, int>>> getAdjacencyList(const std::vector<std::vector<std::string>> &edges)
{
    std::unordered_map<std::string, std::forward_list<std::pair<std::string, int>>> adj;
    for (const auto &edge : edges)
    {
        const std::pair<std::string, int> forwardEdgePair = {edge[1], atoi(edge[2].c_str())};
        adj[edge[0]].push_front(forwardEdgePair);

        const std::pair<std::string, int> backwardEdgePair = {edge[0], atoi(edge[2].c_str())};
        adj[edge[1]].push_front(backwardEdgePair);
    }
    return adj;
}
void displayAjacency(const std::vector<std::vector<std::string>> &edges)
{
    std::unordered_map<std::string, std::forward_list<std::pair<std::string, int>>> adj = getAdjacencyList(edges);
    for (const auto &vertex : adj)
    {
        std::cout << vertex.first << ": ";
        for (const auto &edge : vertex.second)
        {
            std::cout << "{ " << edge.first << "," << edge.second << " }" << ",";
        }
        std::cout << std::endl;
    }
}
void inputEdges(std::vector<std::vector<std::string>> &edges, const size_t &E)
{
    for (size_t i = 0; i < E; i++)
    {
        std::string edge;
        std::string from;
        std::string to;
        std::string weight;

        std::cout << "Enter edge no. " << (i + 1) << " : ";
        if (std::getline(std::cin, edge, '\n'))
        {
            std::stringstream ss(edge);
            ss >> from >> to >> weight;
            edges.push_back({from, to, weight});
        }
    }
}