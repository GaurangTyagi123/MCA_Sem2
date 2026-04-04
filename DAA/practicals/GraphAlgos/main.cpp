#include "prims.cpp"

int main()
{
    // std::vector<std::vector<std::string>> edges = {
    //     {"a", "b", "1"},
    //     {"a", "d", "2"},
    //     {"b", "c", "3"},
    //     {"c", "d", "4"},
    // };
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
    std::map<std::string, std::string> parent = MST_Prims(edges, "a");
    for (const auto &p : parent)
    {
        std::cout << p.first << "-" << p.second << std::endl;
    }

    return 0;
}