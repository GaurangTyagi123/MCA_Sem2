#include "merge_sort.h"

void merge(std::vector<std::vector<value>> &data, const std::string &schemaStr, const std::string &key, ReportType &rep, const size_t &low, const size_t &mid, const size_t &high)
{
    const size_t sortKey = getSortKey(key, schemaStr);
    const size_t len_1 = (mid - low) + 1;
    const size_t len_2 = (high - mid);
    std::vector<std::vector<value>> left(len_1), right(len_2);

    for (int i = 0; i < len_1; i++)
    {
        left[i] = data[low + i];
    }
    for (int j = 0; j < len_2; j++)
    {
        right[j] = data[mid + 1 + j];
    }
    size_t k = low;
    size_t iter1 = 0, iter2 = 0;
    while (iter1 < len_1 && iter2 < len_2)
    {
        rep.comparisons++;
        if (left[iter1][sortKey] <= right[iter2][sortKey])
        {
            data[k] = left[iter1];
            rep.assignments++;
            ++iter1;
        }
        else if (left[iter1][sortKey] > right[iter2][sortKey])
        {
            data[k] = right[iter2];
            rep.assignments++;
            ++iter2;
        }

        ++k;
    }
    while (iter1 < len_1)
    {
        data[k] = left[iter1];
        rep.assignments++;
        ++iter1;
        ++k;
    }
    while (iter2 < len_2)
    {
        data[k] = right[iter2];
        rep.assignments++;
        ++iter2;
        ++k;
    }
}
void mergeSort(std::vector<std::vector<value>> &data, const std::string &schemaStr, const std::string &key, ReportType &rep, const size_t &low, const size_t &high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(data, schemaStr, key, rep, low, mid);
        mergeSort(data, schemaStr, key, rep, mid + 1, high);
        merge(data, schemaStr, key,rep, low, mid, high);
    }
}