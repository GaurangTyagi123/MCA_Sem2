#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "parse_data.h"

void mergeSort(std::vector<std::vector<value>> &, const std::string &, const std::string &, ReportType &rep, const size_t &, const size_t &);
void merge(std::vector<std::vector<value>> &, const std::string &, const std::string &,ReportType &rep, const size_t &, const size_t &, const size_t &);

#endif