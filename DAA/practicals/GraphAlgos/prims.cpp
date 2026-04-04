#include <queue>
#include <map>
#include <climits>


std::map<std::string, std::string> MST_Prims(std::vector<std::vector<std::string>> &edges, const std::string &source)
{
    const std::unordered_map<std::string, std::forward_list<std::pair<std::string, int>>> adj = getAdjacencyList(edges);
    const size_t V = adj.size();
    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, customComparator> queue;
    std::map<std::string, bool> visited;
    std::map<std::string, std::string> parent;
    std::map<std::string, int> key;

    parent[source] = "end";
    for (const auto &vertex : adj)
    {
        key[vertex.first] = INT_MAX;
    }
    for (const auto &edge : adj.at(source))
    {
        queue.emplace(edge.first, edge.second);
        parent[edge.first] = source;
        key[edge.first] = edge.second;
    }
    visited[source] = true;
    key[source] = 0;

    while (visited.size() != V && !queue.empty())
    {
        const std::pair<std::string, int> newNode = queue.top();
        queue.pop();
        if (visited[newNode.first])
            continue;
        for (const auto &edge : adj.at(newNode.first))
        {

            if (!visited.count(edge.first) && edge.second < key[edge.first])
            {
                queue.emplace(edge.first, edge.second);
                parent[edge.first] = newNode.first;
                key[edge.first] = edge.second;
            }
        }
        visited[newNode.first] = true;
    }
    return parent;
}