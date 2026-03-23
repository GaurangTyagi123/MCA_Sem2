#include "./SortingAlgos/linear_sort.cpp"
#include "./SortingAlgos/data_generator.cpp"

double applySort(const std::string &schemaStr, const std::string &file, const std::string &output, const std::string &key)
{
    // data array
    std::vector<std::vector<value>> data;

    // reading file
    readFile(file, schemaStr, data, true);

    // std::cout << data.size() << std::endl;
    // sorting data
    double rep = radixSort(data, schemaStr, key);

    // writing output
    writeFile(output, schemaStr, data);

    return rep;
}

int main()
{
    const std::string pool = "./Data/practical_6_data/synthetic_data.csv";
    const std::string poolSchema = "name:str,age:int";

    const std::vector<size_t> datasizes = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    std::ofstream report_name("./Charts/radix_sort/report_name.csv", std::ios::out);
    report_name << "dataset,average_time\n";

    std::ofstream report_age("./Charts/radix_sort/report_age.csv", std::ios::out);
    report_age << "dataset,average_time\n";

    std::ofstream report_both("./Charts/radix_sort/report_name_age.csv", std::ios::out);
    report_both << "dataset,average_time\n";

    for (const size_t &size : datasizes)
    {
        double total_time = 0;
        for (int i = 0; i < 10; i++)
        {
            generateData(pool, "./Data/practical_6_data/", poolSchema, size);
            const std::string inputFile = "./Data/practical_6_data/" + std::to_string(size) + "_dataset.csv";
            const std::string outputFile = "./Data/practical_6_data/output/name/" + std::to_string(size) + "_dataset.csv";
            total_time += applySort(poolSchema, inputFile, outputFile, "name");
        }
        report_name << size << "," << total_time / 10 << std::endl;

        total_time = 0;
        for (int i = 0; i < 10; i++)
        {
            generateData(pool, "./Data/practical_6_data/", poolSchema, size);
            const std::string inputFile = "./Data/practical_6_data/" + std::to_string(size) + "_dataset.csv";
            const std::string outputFile = "./Data/practical_6_data/output/age/" + std::to_string(size) + "_dataset.csv";
            total_time += applySort(poolSchema, inputFile, outputFile, "age");
        }
        report_age << size << "," << total_time / 10 << std::endl;

        total_time = 0;
        for (int i = 0; i < 10; i++)
        {
            generateData(pool, "./Data/practical_6_data/", poolSchema, size);
            const std::string inputFile = "./Data/practical_6_data/" + std::to_string(size) + "_dataset.csv";
            const std::string outputFile = "./Data/practical_6_data/output/name_age/" + std::to_string(size) + "_dataset.csv";
            total_time += applySort(poolSchema, inputFile, outputFile, "name");
            total_time += applySort(poolSchema, inputFile, outputFile, "age");
        }
        report_both << size << "," << total_time / 10 << std::endl;
    }
    report_age.close();
    report_name.close();
    report_both.close();
    return 0;
}