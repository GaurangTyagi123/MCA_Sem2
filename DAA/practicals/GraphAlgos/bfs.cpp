#include <queue>

void bfs(const std::vector<std::vector<std::string>> &edges, const std::string &source)
{
    const std::unordered_map<std::string, std::forward_list<std::pair<std::string, int>>> adj = getAdjacencyList(edges);
    std::unordered_map<std::string, bool> visited(adj.size());
    std::ofstream strm("/home/gaurang/d_drive/College Material/MCA_Sem2/DAA/practicals/Data/practical_7_data/bfs.csv", std::ios::out);
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
            strm << nextNode << ":" << edge.first << "," << edge.second << "\n";
            if (visited.count(edge.first) <= 0)
            {
                visited[edge.first] = true;
                queue.emplace(edge.first);
            }
        }
    }
    strm.close();
}