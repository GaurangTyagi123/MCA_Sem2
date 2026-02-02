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
    std::string schemaStr = "age:int,job:str,marital:str,education:str,default:str,balance:int,housing:str,loan:str,contact:str,day:str,month:str,duration:str,campaign:str,pdays:str,previous:int,poutcome:str,y:str";
    std::string filePath = "./Data/practical_2_data/bank-full.csv";
    std::string outputPath = "./Data/practical_2_data/bank.csv";

    applySort(schemaStr, filePath, outputPath, "age");

    return 0;
}