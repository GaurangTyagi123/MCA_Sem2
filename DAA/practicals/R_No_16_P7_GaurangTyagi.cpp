#include "./GraphAlgos/init.cpp"
#include "./GraphAlgos/bfs.cpp"
#include "./GraphAlgos/dfs.cpp"
#include "./GraphAlgos/djikstra.cpp"
#include "./GraphAlgos/kruskal.cpp"
#include "./GraphAlgos/prims.cpp"

int main()
{
    std::vector<std::vector<std::string>> edges = {
        {"a", "b", "4"},
        {"a", "h", "8"},
        {"b", "c", "8"},
        {"b", "h", "11"},
        {"c", "i", "2"},
        {"c", "d", "7"},
        {"c", "f", "4"},
        {"d", "f", "14"},
        {"d", "e", "9"},
        {"e", "f", "10"},
        {"f", "g", "2"},
        {"g", "i", "6"},
        {"g", "h", "1"},
        {"h", "i", "7"},
    };
    std::cout << "BFS:- " << std::endl;
    bfs(edges, "a");
    std::cout << "_____________________________" << std::endl;

    std::cout << "DFS:- " << std::endl;
    dfs(edges, "a");
    std::cout << "_____________________________" << std::endl;

    std::cout << "DJIKSTRA:- " << std::endl;
    std::unordered_map<std::string, int> dist = djikstra(edges, "a");
    for (const auto &d : dist)
    {
        std::cout << d.first << "-" << d.second << std::endl;
    }
    std::cout << "_____________________________" << std::endl;

    std::cout << "PRIMS:- " << std::endl;
    std::map<std::string, std::pair<std::string, int>> parent = MST_Prims(edges, "a");
    for (const auto &p : parent)
    {
        std::cout << p.first << " - " << p.second.first << " : " << p.second.second << std::endl;
    }
    std::cout << "_____________________________" << std::endl;

    std::cout << "KRUSKAL:- " << std::endl;
    MST_Kruskal(edges);
    std::cout << "_____________________________" << std::endl;

    return 0;
}