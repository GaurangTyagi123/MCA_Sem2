#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include "parse_data.h"

size_t part(std::vector<std::vector<value>> &, const std::string &, const std::string &,ReportType& rep, const size_t &, const size_t &);
void quickSort(std::vector<std::vector<value>> &data, const std::string &, const std::string &,ReportType& rep, const size_t &, const size_t &);

#endif