#include <queue>
#include <limits>


std::unordered_map<std::string, int> djikstra(const std::vector<std::vector<std::string>> &edges, const std::string &source)
{
    const std::unordered_map<std::string, std::forward_list<std::pair<std::string, int>>> adj = getAdjacencyList(edges);
    std::unordered_map<std::string, int> dist(adj.size());
    const int INF = std::numeric_limits<int>::max();

    for (const auto &vertex : adj)
    {
        dist[vertex.first] = INF;
    }

    if (!dist.count(source))
    {
        dist[source] = INF;
    }

    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, customComparator>
        queue;

    queue.emplace(source, 0);
    dist[source] = 0;
    while (!queue.empty())
    {
        std::pair<std::string, int> from = queue.top();
        queue.pop();

        if (from.second != dist[from.first])
        {
            continue;
        }

        if (!adj.count(from.first))
        {
            continue;
        }

        for (const auto &to : adj.at(from.first))
        {
            if (dist[from.first] != INF && dist[to.first] > dist[from.first] + to.second)
            {
                dist[to.first] = dist[from.first] + to.second;
                queue.emplace(to.first, dist[to.first]);
            }
        }
    }
    return dist;
}