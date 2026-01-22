#include "sorting.h"
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <chrono>

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
    std::string generator_path = "python ./data/generator.py ";
    generator_path.append(std::to_string(n));
    std::system(generator_path.c_str());

    std::fstream strm;

    std::string input_path = "./data/";
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
 * @return Time taken to sort the dataset
 * @details
 * Sorting behavior:
 *- 0 : Sort by age
 *- 1 : Sort by name
 *- 2 : Sort by name, using age as a tie-breaker
 *
 * If there is no data, the function returns immediately.
 */
Report Sorting_Algorithms::insertion_sort(size_t sort_field) const
{
    Report rep;
    if (!data)
    {
        std::cout << "There is no data" << std::endl;
        return rep;
    }
    else
    {
        auto start = std::chrono::steady_clock::now();
        switch (sort_field)
        {
        case 0:
            for (int i = 1; i < n; i++)
            {
                Person key = data[i];
                int j = i - 1;
                while (j >= 0 && data[j].name.compare(key.name) > 0)
                {
                    rep.comparisons++;
                    data[j + 1] = data[j];
                    rep.assignments++;
                    --j;
                }
                data[j + 1] = key;
                rep.assignments++;
            }
            break;
        case 1:
            for (int i = 1; i < n; i++)
            {
                Person key = data[i];
                int j = i - 1;
                while (j >= 0 && data[j].age > key.age)
                {
                    rep.comparisons++;
                    data[j + 1] = data[j];
                    rep.assignments++;
                    --j;
                }
                data[j + 1] = key;
                rep.assignments++;
            }
            break;
        case 2:
            for (int i = 1; i < n; i++)
            {
                Person key = data[i];
                int j = i - 1;
                while (j >= 0 && (data[j].age > key.age || (data[j].age == key.age && data[j].name.compare(key.name) > 0)))
                {
                    rep.comparisons++;
                    data[j + 1] = data[j];
                    rep.assignments++;
                    --j;
                }

                data[j + 1] = key;
                rep.assignments++;
            }
            break;
        default:
            std::cout << "INVALID OPTION" << std::endl;
        }
        auto stop = std::chrono::steady_clock::now();
        std::chrono::duration<double> time = stop - start;
        rep.time = time.count();

        std::string output_path = "./output/";
        output_path.append(std::to_string(n) + "_set.csv");
        std::fstream strm(output_path, std::ios::out);

        for (int i = 0; i < n; i++)
        {
            strm << data[i].name << "," << data[i].age << "\r";
        }
        strm.close();
        return rep;
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
/**
 * @brief Function to generate report for datasets of any size
 * @param dataset_size size of the dataset
 * @details
 * Create or edit a file called report.csv.
 * Generate 10 random datasets of size dataset_size and calculates the average running time for the algorithm
 * and writes it in report.csv file
 */
void generate_report_insertion_sort(size_t dataset_size, size_t option, std::string report_name)
{
    std::string file_path = "./data/" + report_name;
    std::fstream strm(file_path, std::ios::app);
    Sorting_Algorithms s(dataset_size);

    double avg_time = 0;
    double avg_comparisons = 0;
    double avg_assignments = 0;

    for (int set = 0; set < 10; set++)
    {
        Sorting_Algorithms *s = new Sorting_Algorithms(dataset_size);
        Report rep = s->insertion_sort(option);
        avg_time += rep.time;
        avg_comparisons += rep.comparisons;
        avg_assignments += rep.assignments;

        delete s;
    }
    avg_time /= 10;
    avg_comparisons /= 10;
    avg_assignments /= 10;

    if (strm.is_open())
    {
        std::cout << "DATASET SIZE: " << dataset_size << " AVERAGE TIME: " << (avg_time) << " AVERAGE COMPARISONS: " << avg_comparisons << " AVERAGE ASSIGNMENTS: " << avg_assignments << std::endl;
        strm << dataset_size << "," << avg_time << "," << avg_comparisons << "," << avg_assignments << "\r";
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
    std::cout << std::endl;
    const int dataset_sizes[] = {10, 20, 30, 40, 50, 60, 70};

    for (int size : dataset_sizes)
    {
        generate_report_insertion_sort(size, 0, "sort_by_age_report.csv");
    }
    std::system("python ./charts/visualizer.py sort_by_age_report.csv sort_by_age_plot.png");

    std::cout << std::endl;
    for (int size : dataset_sizes)
    {
        generate_report_insertion_sort(size, 1, "sort_by_name_report.csv");
    }
    std::system("python ./charts/visualizer.py sort_by_name_report.csv sort_by_name_plot.png");

    std::cout << std::endl;
    for (int size : dataset_sizes)
    {
        generate_report_insertion_sort(size, 2, "sort_by_name_age_report.csv");
    }
    std::system("python ./charts/visualizer.py sort_by_name_age_report.csv sort_by_name_age_plot.png");

    openImage("./charts/sort_by_age_plot.png");
    openImage("./charts/sort_by_name_plot.png");
    openImage("./charts/sort_by_name_age_plot.png");

    return 0;
}