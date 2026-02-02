#include <iostream>
#include "./SortingAlgos/insertion_sort.cpp"
#include "./SortingAlgos/parse_data.cpp"
#include <random>

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

void generate_datasets(const std::vector<std::string> &names, const std::vector<double> &ages)
{
    std::vector<int> sizes = {10, 20, 30, 40, 50, 60, 70};
    for (int &size : sizes)
    {
        srand(time(0));
        std::string filePath = "./Data/practical_1_data/input/" + std::to_string(size) + "_set.csv";
        std::ofstream strm(filePath, std::ios::out);
        for (int i = 0; i < size; i++)
        {
            size_t index = random() % 20;
            strm << names[index] << "," << ages[index]<<"\r";
        }
        strm.close();
    }
}
void read_pools()
{
    std::fstream nameStrm("./Data/practical_1_data/name_repo.csv", std::ios::in | std::ios::out);
    std::fstream ageStrm("./Data/practical_1_data/age_repo.csv", std::ios::in | std::ios::out);

    std::vector<std::string> names;
    std::vector<double> ages;

    std::string name;
    std::string age;
    while (std::getline(nameStrm, name))
    {
        names.push_back(name);
    }
    while (std::getline(ageStrm, age))
    {
        ages.push_back(atof(age.c_str()));
    }
    generate_datasets(names, ages);
    nameStrm.close();
    ageStrm.close();
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
    std::string schemaStr = "name:str,age:double";
    std::string filePath = "./Data/practical_1_data/input/";
    std::string outputPath = "./Data/practical_1_data/output/";
    std::fstream strm("./Charts/insertion_sort/report.csv", std::ios::out);
    strm << "dataset,age_comparisons,age_assignments,name_comparisons,name_assignments\r";

    for (int i = 10; i <= 70; i += 10)
    {
        int avg_comparisons_age = 0;
        int avg_assignments_age = 0;

        int avg_comparisons_name = 0;
        int avg_assignments_name = 0;

        for (int j = 0; j < 10; j++)
        {
            std::string file = filePath + std::to_string(i) + "_set.csv";
            std::string output = outputPath + "age/" + std::to_string(i) + "_set_age.csv";
            ReportType rep = applySort(schemaStr, file, output, "age");

            avg_comparisons_age += rep.comparisons;
            avg_assignments_age += rep.assignments;
        }
        for (int j = 0; j < 10; j++)
        {
            std::string file = filePath + std::to_string(i) + "_set.csv";
            std::string output = outputPath + "name/" + std::to_string(i) + "_set_name.csv";

            ReportType rep = applySort(schemaStr, file, output, "name");

            avg_comparisons_name += rep.comparisons;
            avg_assignments_name += rep.assignments;
        }
        for (int j = 0; j < 10; j++)
        {
            std::string file = filePath + std::to_string(i) + "_set.csv";
            std::string output = outputPath + "name_age/" + std::to_string(i) + "_set_name_age.csv";
            applySort(schemaStr, file, output, "age");
            applySort(schemaStr, file, output, "name");
        }
        avg_assignments_age /= 10;
        avg_comparisons_age /= 10;
        avg_assignments_name /= 10;
        avg_comparisons_name /= 10;

        strm << i << "," << avg_assignments_age << "," << avg_comparisons_age << "," << avg_assignments_name << "," << avg_comparisons_name << "\r";
    }
    strm.close();
    std::system("python3 ./Charts/visualize.py ./Charts/insertion_sort/report.csv");
    openImage("./Charts/insertion_sort/report.png");

    return 0;
}