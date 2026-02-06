#include "parse_data.h"
#include <sstream>
#include <fstream>
#include <iostream>
/**
 * @brief 
 */
std::vector<Coltype> parseSchema(const std::string &schema)
{
    std::vector<Coltype> cols;
    std::stringstream schema_stream(schema);

    std::string col;
    std::string name;
    std::string type;

    while (std::getline(schema_stream, col, ','))
    {
        std::stringstream col_stream(col);
        std::getline(col_stream, name, ':');
        std::getline(col_stream, type, ':');

        Coltype val;
        val.name = name;
        if (type == "int")
            val.type = Type::INT;
        if (type == "str")
            val.type = Type::STRING;
        if (type == "double")
        {
            val.type = Type::DOUBLE;
        }
        cols.push_back(val);
    }
    return cols;
}

value parseValue(const std::string &value, size_t pos, const std::string &schemaStr)
{
    std::vector<Coltype> schema = parseSchema(schemaStr);
    
    switch (schema[pos].type)
    {
    case Type::INT:
        return std::stoi(value);
    case Type::DOUBLE:
        return std::atof(value.c_str());
    case Type::STRING:
        return value;
    default:
        return value;
    }
}

void readFile(const std::string &filePath, const std::string &schemaStr, std::vector<std::vector<value>> &data)
{
    std::fstream strm(filePath, std::ios::in);

    if (strm.is_open())
    {
        std::string record;

        while (getline(strm, record,'\n'))
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
}
void writeFile(const std::string &file, const std::string &schemaStr, std::vector<std::vector<value>> &data)
{
    std::fstream strm(file, std::ios::out);
    std::vector<Coltype> schema = parseSchema(schemaStr);

    for (Coltype &col : schema)
    {
        strm << col.name << ",";
    }
    strm << "\r";
    if (strm.is_open())
    {
        for (auto &rec : data)
        {
            for (auto &cell : rec)
            {
                std::visit([&strm](auto &val)
                           { strm << val << ','; },
                           cell);
            }
            strm << '\n';
        }
        strm.close();
    }
}

int getSortKey(const std::string &key, const std::string &schemaStr)
{
    std::vector<Coltype> schema = parseSchema(schemaStr);

    for (int i = 0; i < schema.size(); i++)
    {
        if (schema[i].name == key)
            return i;
    }
    return 0;
}