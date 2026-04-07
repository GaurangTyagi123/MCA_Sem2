# Assignment - 9

## Ques. Write a C++ program to simulate dynamic memory partitioning using the following allocation strategies:
        1. First Fit.
        2. Next Fit.

### Code
```cpp
#include <iostream>
#include <vector>
#include <sstream>

void displayAllocation(const std::vector<int> &allocations)
{
    std::cout << "------------------------------------------------------------------------" << std::endl;
    for (size_t i = 0; i < allocations.size(); i++)
    {
        int alloc = allocations[i] >= 0 ? allocations[i] + 1 : -1;
        std::cout << "Process: " << (i + 1) << " -> " << "Block: " << alloc << std::endl;
    }
    std::cout << "------------------------------------------------------------------------" << std::endl;
}
int firstFit(const size_t &processSize, std::vector<int> &blocks)
{
    for (size_t i = 0; i < blocks.size(); i++)
    {
        if (blocks[i] >= processSize)
        {
            blocks[i] -= processSize;
            return i;
        }
    }
    return -1;
}
int nextFit(const size_t &processSize, std::vector<int> &blocks, const size_t &allocIndex)
{
    size_t iter = allocIndex;
    while ((iter + 1) % blocks.size() != allocIndex)
    {
        if (blocks[iter] >= processSize)
        {
            blocks[iter] -= processSize;
            return iter;
        }
        iter = (iter + 1) % blocks.size();
    }
    return -1;
}
void fit(const size_t &mBlocks, const size_t &nProcesses)
{
    std::vector<int> blocks(mBlocks, 0);
    std::vector<size_t> processes(nProcesses, 0);
    std::vector<int> allocation(nProcesses, -1);

    std::cout << "Enter process sizes : ";
    for (size_t i = 0; i < nProcesses; i++)
    {
        std::string procSizes;
        std::cin >> procSizes;

        std::stringstream ss(procSizes);
        std::string size;
        std::getline(ss, size);
        processes[i] = std::stoi(size);
    }
    std::cout << "Enter block sizes : ";
    for (size_t i = 0; i < mBlocks; i++)
    {
        std::string blockSizes;
        std::cin >> blockSizes;

        std::stringstream ss(blockSizes);
        std::string size;
        std::getline(ss, size);
        blocks[i] = std::stoi(size);
    }

    std::cout << "FIRST FIT" << std::endl;
    std::vector<int> blocksFirst(blocks);
    for (size_t i = 0; i < processes.size(); i++)
    {
        allocation[i] = firstFit(processes[i], blocksFirst);
    }
    displayAllocation(allocation);
    std::cout << "NEXT FIT" << std::endl;
    int nextIndex = 0;
    std::vector<int> blocksNext(blocks);
    for (size_t i = 0; i < processes.size(); i++)
    {
        allocation[i] = nextFit(processes[i], blocksNext, nextIndex);
        if (allocation[i] >= 0)
            nextIndex = allocation[i];
    }
    displayAllocation(allocation);
}

int main()
{
    fit(5, 4);
    return 0;
}
```

### OUTPUT
![1775574287788](image/ass-9/1775574287788.png)