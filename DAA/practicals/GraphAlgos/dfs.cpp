#include <stack>

void dfs(const std::vector<std::vector<std::string>> &edges, const std::string &source)
{
    const std::unordered_map<std::string, std::forward_list<std::pair<std::string, int>>> adj = getAdjacencyList(edges);
    std::unordered_map<std::string, bool> visited(adj.size());
    std::stack<std::string> stack;

    stack.emplace(source);
    visited[source] = true;
    while (!stack.empty())
    {
        std::string nextNode = stack.top();
        std::cout << nextNode << std::endl;
        stack.pop();

        auto iter = adj.at(nextNode).begin();
        while (iter != adj.at(nextNode).end() && visited[iter->first])
        {
            std::advance(iter, 1);
        }
        if (iter != adj.at(nextNode).end())
        {
            visited[nextNode] = true;
            stack.emplace(iter->first);
        }
    }
}