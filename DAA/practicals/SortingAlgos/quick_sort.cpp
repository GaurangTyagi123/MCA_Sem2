#include "quick_sort.h"
#include <iostream>

size_t part(std::vector<std::vector<value>> &data, const std::string &schemaStr, const std::string &key, ReportType &rep, const size_t &low, const size_t &high)
{
    const size_t sortKey = getSortKey(key, schemaStr);
    int left = int(low) - 1;
    int right = int(high) + 1;
    auto pivot = data[low][sortKey];

    while (left < right)
    {
        do
        {
            ++left;
            rep.comparisons++;
        } while (data[left][sortKey] < pivot);
        do
        {
            --right;
            rep.comparisons++;
        } while (data[right][sortKey] > pivot);
        if (left < right)
        {
            std::swap(data[left], data[right]);
            rep.assignments += 2;
        }
    }
    return right;
}

void quickSort(std::vector<std::vector<value>> &data, const std::string &schemaStr, const std::string &key, ReportType &rep, const size_t &low, const size_t &high)
{
    if (low < high)
    {
        size_t pivotIndex = part(data, schemaStr, key, rep, low, high);
        quickSort(data, schemaStr, key, rep, low, pivotIndex);
        quickSort(data, schemaStr, key, rep, pivotIndex + 1, high);
    }
}
void randomizedQuickSort(std::vector<std::vector<value>> &data, const std::string &schemaStr, const std::string &key, ReportType &rep, const size_t &low, const size_t &high)
{
    srand(time(0));
    if (low < high)
    {
        size_t randomPivotIndex = random() % data.size();
        std::swap(data[randomPivotIndex], data[low]);
        size_t pivotIndex = part(data, schemaStr, key, rep, low, high);
        quickSort(data, schemaStr, key, rep, low, pivotIndex);
        quickSort(data, schemaStr, key, rep, pivotIndex + 1, high);
    }
}