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
    quickSort(data, key, schemaStr, rep, 0, data.size() - 1);

    // writing output
    std::cout << "WRITING THE OUTPUT" << std::endl;
    writeFile(output, schemaStr, data);

    return rep;
}
void generate_datasets(const std::string &schemaStr, const std::string &filepath)
{
    std::vector<Coltype> columns = parseSchema(schemaStr);
    std::fstream strm(filepath, std::ios::in);
    std::vector<std::vector<value>> data;

    if (strm.is_open())
    {
        std::string record;
        while (getline(strm, record, '\n'))
        {
            std::stringstream recordStream(record);
            std::string cell;

            std::vector<value> temp;
            size_t index = 0;
            while (getline(recordStream, cell, ','))
            {
                value val = parseValue(cell, index++, schemaStr);
                temp.push_back(val);
            }
            data.push_back(temp);
        }
        strm.close();
    }
    else
    {
        std::cout << "ERROR: cannot open file" << std::endl;
    }
    const std::vector<int> sizes = {10, 20, 30, 40, 50, 60, 70};
    for (const int &size : sizes)
    {
        srand(time(0));
        std::string outPath = "./Data/practical_2_data/input/" + std::to_string(size) + "_set.csv";
        std::ofstream outStrm(outPath, std::ios::out);

        for (int i = 0; i < size; i++)
        {
            size_t index = random() % data.size();
            std::vector<value> record = data[index];
            for (auto &cell : record)
            {
                std::visit([&outStrm](auto &val)
                           { outStrm << val << ','; },
                           cell);
            }
            outStrm << '\r';
        }
        strm.close();
    }
}
void openImage(const std::string &path)
{
#ifdef _WIN32
    // Windows: opens with default app
    std::string cmd = "start \"\" \"" + path + "\"";
    system(cmd.c_str());

#elif __APPLE__
    // macOS
    std::string cmd = "open \"" + path + "\"";
    system(cmd.c_str());

#elif __linux__
    // Linux
    std::string cmd = "xdg-open \"" + path + "\"";
    system(cmd.c_str());

#else
    std::cout << "Unsupported OS\n";
#endif
}

int main()
{
    std::system("pip install pandas matplotlib seaborn");
    // parameters
    std::string schemaStr = "date:str,open:double,volume:int,high:double,low:double,average:double";
    std::string filePath = "./Data/practical_2_data/input/";
    std::string outputPath = "./Data/practical_2_data/output/";
    std::fstream strm("./Charts/quick_sort/report_4b.csv", std::ios::out);
    strm << "dataset,comparisons,assignments\r";

    for (int i = 10; i <= 70; i += 10)
    {
        int avg_comparisons = 0;
        int avg_assignments = 0;

        for (int j = 0; j < 10; j++)
        {
            std::string file = filePath + std::to_string(i) + "_set.csv";
            std::string output = outputPath + std::to_string(i) + "_set.csv";
            ReportType rep = applySort(schemaStr, file, output, "open");

            avg_comparisons += rep.comparisons;
            avg_assignments += rep.assignments;
        }
        avg_assignments /= 10;
        avg_comparisons /= 10;

        strm << i << "," << avg_assignments << "," << avg_comparisons << "\r";
    }
    strm.close();
    std::system("python3 ./Charts/visualize_2.py ./Charts/quick_sort/report_4b.csv ./Charts/quick_sort/report_4b.png");
    openImage("./Charts/quick_sort/report_4b.png");
    // generate_datasets(schemaStr, filePath);

    return 0;
}
