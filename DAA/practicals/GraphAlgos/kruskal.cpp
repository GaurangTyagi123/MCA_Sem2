#include <algorithm>

class DisjointSet
{
public:
    std::unordered_map<std::string, std::string> parent;
    std::unordered_map<std::string, int> rank;

    DisjointSet(const std::vector<std::string> vertices)
    {
        size_t V = vertices.size();

        for (int i = 0; i < V; i++)
        {
            parent[vertices[i]] = vertices[i];
            rank[vertices[i]] = 0;
        }
    }

    std::string find(std::string x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    void unite(std::string x, std::string y)
    {
        std::string rootX = find(x);
        std::string rootY = find(y);

        if (rootX == rootY)
            return;

        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;

        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;

        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

bool compareEdge(const std::vector<std::string> &a, std::vector<std::string> &b)
{
    return stoi(a[2]) < stoi(b[2]);
}

void MST_Kruskal(std::vector<std::vector<std::string>> &edges)
{
    sort(edges.begin(), edges.end(), compareEdge);
    const std::unordered_map<std::string, std::forward_list<std::pair<std::string, int>>> adj = getAdjacencyList(edges);
    std::vector<std::string> vertices;
    std::ofstream strm("/home/gaurang/d_drive/College Material/MCA_Sem2/DAA/practicals/Data/practical_7_data/kruskal.csv", std::ios::out);

    for (const auto &vertex : adj)
    {
        vertices.push_back(vertex.first);
    }
    DisjointSet ds(vertices);

    for (const std::vector<std::string> &edge : edges)
    {
        std::string u = edge[0];
        std::string v = edge[1];
        if (ds.find(u) != ds.find(v))
        {
            std::cout << edge[0] << " - " << edge[1] << " : " << edge[2] << std::endl;
            strm << edge[0] << ":" << edge[1] << "," << edge[2] << std::endl;
            ds.unite(u, v);
        }
    }
}
