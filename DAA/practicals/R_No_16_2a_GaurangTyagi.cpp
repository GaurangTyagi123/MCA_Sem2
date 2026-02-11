#include <iostream>
#include "./SortingAlgos/insertion_sort.cpp"
#include "./SortingAlgos/parse_data.cpp"

ReportType applySort(const std::string &schemaStr, const std::string &file, const std::string &output, const std::string &key)
{
    // data array
    std::vector<std::vector<value>> data;

    // reading file
    std::cout << "READING INPUT FILE" << std::endl;
    readFile(file, schemaStr, data);

    // sorting data
    std::cout << "SORTING DATA BASED ON:" << key << std::endl;
    ReportType rep = insertionSort(data, key, schemaStr);

    // writing output
    std::cout << "WRITING THE OUTPUT" << std::endl;
    writeFile(output, schemaStr, data);

    return rep;
}

int main()
{
    // parameters
    std::string schemaStr = "date:str,open:double,volume:int,high:double,low:double,average:double";
    std::string filePath = "./Data/practical_2_data/tesla_stock.csv";
    std::string outputPath = "./Data/practical_2_data/tesla_stock_sorted.csv";

    ReportType rep = applySort(schemaStr, filePath, outputPath, "open");
    std::cout << "Number of comparisons: " << rep.comparisons << std::endl;
    std::cout << "Number of assignments: " << rep.assignments << std::endl;

    return 0;
}
