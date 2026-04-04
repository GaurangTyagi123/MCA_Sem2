#include <queue>

void bfs(const std::vector<std::vector<std::string>> &edges, const std::string &source)
{
    const std::unordered_map<std::string, std::forward_list<std::pair<std::string, int>>> adj = getAdjacencyList(edges);
    std::unordered_map<std::string, bool> visited(adj.size());
    std::queue<std::string> queue;

    queue.emplace(source);
    visited[source] = true;
    while (!queue.empty())
    {
        std::string nextNode = queue.front();
        queue.pop();
        std::cout << nextNode << std::endl;
        for (const auto &edge : adj.at(nextNode))
        {
            if (visited.count(edge.first) <= 0)
            {
                visited[edge.first] = true;
                queue.emplace(edge.first);
            }
        }
    }
}