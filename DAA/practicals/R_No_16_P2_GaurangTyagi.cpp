#include <iostream>
#include "./SortingAlgos/insertion_sort.cpp"
#include "./SortingAlgos/parse_data.cpp"

ReportType applySort(const std::string &schemaStr, const std::string &file, const std::string &output, const std::string &key)
{
    // data array
    std::vector<std::vector<value>> data;

    // reading file
    readFile(file, schemaStr, data);

    // sorting data
    ReportType rep = insertionSort(data, key, schemaStr);

    // writing output
    writeFile(output, schemaStr, data);

    return rep;
}

int main()
{
    // parameters
    std::string schemaStr = "date:str,close:double,volume:str,open:double,high:double,low:double";
    std::string filePath = "./Data/practical_2_data/tesla_stock.csv";
    std::string outputPath = "./Data/practical_2_data/sorted_tesla_stock.csv";

    applySort(schemaStr, filePath, outputPath, "high");

    return 0;
}