#include "sorting.h"

int main()
{
    const int dataset_sizes[] = {10, 20, 30, 40, 50, 60, 70};

    for(int size : dataset_sizes){
        generate_report_insertion_sort(size);
    }

    return 0;
}
