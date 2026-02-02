#include "insertion_sort.h"

ReportType insertionSort(std::vector<std::vector<value>> &data, const std::string &key, const std::string &schemaStr)
{
    int sortKey = getSortKey(key, schemaStr);
    int comparisons = 0;
    int assignments = 0;

    ReportType rep;
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
    rep.assignments = assignments;
    rep.comparisons = comparisons;

    return rep;
}