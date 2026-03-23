#include <random>

void generateData(const std::string &filename, const std::string &outputFile, const std::string &schemaStr, const size_t &size)
{
    std::fstream strm(filename, std::ios::in);
    if (!strm.is_open())
        std::runtime_error("cannot open the file");
    std::vector<std::vector<value>> data;
    readFile(filename, schemaStr, data,false);

    srand(time(0));
    std::vector<std::vector<value>> sample;
    for (size_t i = 0; i < size; i++)
    {
        size_t randomIndex = random() % data.size();
        sample.push_back(data[randomIndex]);
    }
    const std::string outputFilename = outputFile + std::to_string(size) + "_dataset.csv";
    writeFile(outputFilename, schemaStr, sample);
    strm.close();
}