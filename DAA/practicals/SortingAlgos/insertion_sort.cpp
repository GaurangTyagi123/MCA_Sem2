#include "insertion_sort.h"
#include "chrono"

ReportType insertionSort(std::vector<std::vector<value>> &data, const std::string &key, const std::string &schemaStr)
{
    int sortKey = getSortKey(key, schemaStr);
    int comparisons = 0;
    int assignments = 0;

    ReportType rep;
    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < data.size(); i++)
    {
        auto key = data[i][sortKey];
        auto key_row = data[i];
        int j = i - 1;
        while (j >= 0 &&  key < data[j][sortKey])
        {
            comparisons++;
            data[j + 1] = data[j];
            assignments++;
            --j;
        }
        data[j + 1] = key_row;
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> duration = end - start;
    
    rep.time = duration.count();
    rep.assignments = assignments;
    rep.comparisons = comparisons;

    return rep;
}