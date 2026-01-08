#include "sorting.h"
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

// Default Contructor
Sorting_Algorithms::Sorting_Algorithms() : n(0)
{
    this->data = nullptr;
}

// Parameter Constructor
/**
 * @brief Initialize the data array
 * @param input_size {size_t} Number of persons
 */
Sorting_Algorithms::Sorting_Algorithms(int input_size) : n(input_size)
{

    /**
     * @details initialize the data array , runs the generator.py file to generate n number of random records,
     * opens the file containing generated data and stores them in the data array,
     */
    data = new Person[n];
    std::string generator_path = "python3 /home/shared/College\\ Material/MCA_Sem2/DAA/data/generator.py ";
    generator_path.append(std::to_string(n));
    std::system(generator_path.c_str());

    std::fstream strm;

    std::string input_path = "/home/shared/College Material/MCA_Sem2/DAA/data/";
    input_path.append(std::to_string(n) + "_set.csv");
    strm.open(input_path, std::ios::in);

    if (strm.is_open())
    {
        std::string line;
        int iter1 = 0;
        srand(0);
        while (getline(strm, line))
        {
            std::stringstream ss(line);
            std::string value;

            std::string *temp = new std::string[2];
            int iter2 = 0;
            while (getline(ss, value, ','))
            {
                temp[iter2++] = value;
            }
            data[iter1].name = temp[0];
            data[iter1].age = atof(temp[1].c_str());
            ++iter1;
        }
        strm.clear();
        strm.close();
    }
    else
    {
        std::cerr << "There was an error opening the file";
    }
}

// destructor
Sorting_Algorithms::~Sorting_Algorithms()
{
    delete[] data;
}

// getter for the number of persons
int Sorting_Algorithms::getSize() const
{
    return n;
}

// setter for the number of persons
void Sorting_Algorithms::setSize(int input_size)
{
    n = input_size;
}

/**
 * @brief Sort the data array based on sort_field
 *
 * @param sort_field Index of the field used for sorting.
 *
 * @details
 * Sorting behavior:
 *- 0 : Sort by age
 *- 1 : Sort by name
 *- 2 : Sort by name, using age as a tie-breaker
 *
 * If there is no data, the function returns immediately.
 */
void Sorting_Algorithms::insertion_sort(size_t sort_field) const
{
    if (!data)
        std::cout << "There is no data" << std::endl;
    else
    {
        switch (sort_field)
        {
        case 0:
            for (int i = 1; i < n; i++)
            {
                Person key = data[i];
                int j = i - 1;
                while (j >= 0 && data[j].name.compare(key.name) > 0)
                {
                    data[j + 1] = data[j];
                    --j;
                }
                data[j + 1] = key;
            }
            break;
        case 1:
            for (int i = 1; i < n; i++)
            {
                Person key = data[i];
                int j = i - 1;
                while (j >= 0 && data[j].age > key.age)
                {
                    data[j + 1] = data[j];
                    --j;
                }
                data[j + 1] = key;
            }
            break;
        case 2:
            for (int i = 1; i < n; i++)
            {
                Person key = data[i];
                int j = i - 1;
                while (j >= 0 && (data[j].name.compare(key.name) > 0 || (data[j].name.compare(key.name) == 0 && data[j].age > key.age)))
                {
                    data[j + 1] = data[j];
                    --j;
                }

                data[j + 1] = key;
            }
            break;
        default:
            std::cout << "INVALID OPTION" << std::endl;
        }
    }
}
/**
 * @brief display contents of the data array
 * @param NA
 */
void Sorting_Algorithms::display() const
{
    for (int i = 0; i < n; i++)
    {
        std::cout << data[i].name << " - " << data[i].age << std::endl;
    }
}
