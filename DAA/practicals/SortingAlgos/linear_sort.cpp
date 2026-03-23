#include "parse_data.cpp"
#include <chrono>

void countSort(std::vector<std::vector<value>> &data, const std::vector<Coltype> &schema, const size_t &keyIndex, const size_t &index)
{

    std::vector<std::vector<value>> output(data.size());
    std::vector<size_t> countFreq;

    if (schema[keyIndex].type == Type::INT)
        countFreq.resize(11, 0);
    if (schema[keyIndex].type == Type::STRING)
        countFreq.resize(26, 0);

    size_t cf_size = countFreq.size();
    for (size_t i = 0; i < data.size(); i++)
    {
        if (schema[keyIndex].type == Type::INT)
        {
            std::visit([&countFreq](const auto &val)
                       { 
                    if constexpr(std::is_same_v<decltype(val), const int &>)
                    countFreq[val - 10] += 1; },
                       data[i][keyIndex]);
        }
        if (schema[keyIndex].type == Type::STRING)
        {
            std::visit([&countFreq, &index](const auto &val)
                       { 
                        if constexpr(std::is_same_v<decltype(val), const std::string &>)
                        {
                               char character = val[index];
                               countFreq[std::tolower(character) - 97] += 1;
                            } },
                       data[i][keyIndex]);
        }
    }
    for (size_t i = 1; i < cf_size; i++)
    {
        countFreq[i] += countFreq[i - 1];
    }

    for (int i = data.size() - 1; i >= 0; --i)
    {

        std::visit([&countFreq, &index, &output, &data, &i](const auto &val)
                   {
            if constexpr (std::is_same_v<decltype(val), const int &>)
            {
                output[countFreq[val - 10] - 1] = data[i];
                countFreq[val - 10] -= 1;
            }
            if constexpr (std::is_same_v<decltype(val), const std::string &>)
            {
                char character = val[index];
                output[countFreq[std::tolower(character) - 97]-1] = data[i];
                countFreq[std::tolower(character) - 97] -= 1;
            } },
                   data[i][keyIndex]);
    }
    data = output;
}
double radixSort(std::vector<std::vector<value>> &data, const std::string &schemaStr, const std::string &key)
{
    const std::vector<Coltype> schema = parseSchema(schemaStr);
    const size_t keyIndex = getSortKey(key, schemaStr);

    auto start = std::chrono::system_clock::now();
    if (schema[keyIndex].type == Type::INT)
    {
        for (int i = 1; i >= 0; i--)
        {
            countSort(data, schema, keyIndex, i);
        }
    }
    if (schema[keyIndex].type == Type::STRING)
    {
        for (int i = 9; i >= 0; i--)
        {
            countSort(data, schema, keyIndex, i);
        }
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}
