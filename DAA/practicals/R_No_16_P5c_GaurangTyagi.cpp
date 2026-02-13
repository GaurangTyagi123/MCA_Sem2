#include <iostream>
#include "./SortingAlgos/quick_sort.cpp"
#include "./SortingAlgos/parse_data.cpp"

ReportType applySort(const std::string &schemaStr, const std::string &file, const std::string &output, const std::string &key)
{
    // data array
    std::vector<std::vector<value>> data;

    // Report
    ReportType rep;

    // reading file
    std::cout << "READING INPUT FILE" << std::endl;
    readFile(file, schemaStr, data);

    // sorting data
    std::cout << "SORTING DATA BASED ON:" << key << std::endl;
    randomizedQuickSort(data, schemaStr, key, rep, 0, data.size() - 1);

    // writing output
    std::cout << "WRITING THE OUTPUT" << std::endl;
    writeFile(output, schemaStr, data);

    return rep;
}

int main()
{
    // parameters
    std::string schemaStr = "age:int,job:str,marital:str,education:str,default:str,balance:int,housing:str,loan:str,contact:str,day:str,month:str,duration:str,campaign:str,pdays:str,previous:int,poutcome:str,y:str";
    std::string filePath = "./Data/practical_2_data/bank_full_mini.csv";
    std::string outputPath = "./Data/practical_2_data/bank_mini.csv";

    ReportType rep = applySort(schemaStr, filePath, outputPath, "age");
    std::cout << "Number of comparisons: " << rep.comparisons << std::endl;

    return 0;
}