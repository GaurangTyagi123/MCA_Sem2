#include "R_No_16_P2_GaurangTyagi.h"
#include <iostream>

int main()
{
    // parseSchema("id:int,age:int,salary:double");
    std::string schemaStr = "date:str,open:double,high:double,low:double,close:double,volume:str";
    std::string file = "./data.csv";
    std::string output = "./output.csv";
    std::string key = "high";

    std::vector<std::vector<value>> data;

    readFile(file, schemaStr, data);
    insertionSort(data, key, schemaStr);
    writeFile(output, schemaStr, data);

    // for (auto &rec : data)
    // {
    //     for (auto &cell : rec)
    //     {
    //         std::visit([](auto &val)
    //                    { std::cout << val << std::endl; }, cell);
    //     }
    // }
    return 0;
}
