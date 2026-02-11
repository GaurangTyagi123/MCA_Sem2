#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

void cryptHelper(const std::string &first, const std::string &second, const std::string &third, std::unordered_map<char, int> &res, std::unordered_map<int, bool> &domain, int domIndex, int strIndex, int carry)
{
    if (strIndex == first.size())
        return;
    if (domain[domIndex])
        cryptHelper(first, second, third, res, domain, domIndex + 1, strIndex, carry);
    else
    {
        char firstCharacter = first[strIndex];
        char secondCharacter = second[strIndex];
        char thirdCharacter = third[strIndex];

        if (res[firstCharacter] == -1)
        {
            res[firstCharacter] = domIndex;
            domain[domIndex] = true;
            cryptHelper(first, second, third, res, domain, 0, strIndex, carry);
            domain[domIndex] = false;
            res[firstCharacter] = -1;
            cryptHelper(first, second, third, res, domain, domIndex + 1, strIndex, carry);
        }
        if (res[secondCharacter] == -1)
        {
            res[secondCharacter] = domIndex;
            domain[domIndex] = true;
            cryptHelper(first, second, third, res, domain, 0, strIndex, carry);
            domain[domIndex] = false;
            res[secondCharacter] = -1;
            cryptHelper(first, second, third, res, domain, domIndex + 1, strIndex, carry);
        }
        int sum = (res[firstCharacter] + res[secondCharacter] + carry) % 10;
        if (domain[sum])
            return;
        if (res[thirdCharacter] == -1)
        {
            res[thirdCharacter] = sum;
            int c = (res[firstCharacter] + res[secondCharacter] + carry) / 10;
            domain[sum] = true;
            cryptHelper(first, second, third, res, domain, 0, strIndex + 1, c);
            res[thirdCharacter] = -1;
            domain[sum] = false;
        }

        if (res[thirdCharacter] != sum)
        {
            domain[res[thirdCharacter]] = false;
            res[thirdCharacter] = sum;
            int c = (res[firstCharacter] + res[secondCharacter] + carry) / 10;
            domain[sum] = true;
            cryptHelper(first, second, third, res, domain, 0, strIndex + 1, c);
        }
    }
}
void crypt(std::string &first, std::string &second, std::string &third, std::unordered_map<char, int> &res)
{
    if (res.size() > 10)
    {
        std::cout << "ERROR: NUMBER OF SYMBOLS GREATER THAN 10" << std::endl;
        return;
    }
    else if (first.size() < third.size() && second.size() < third.size())
    {
        res[third.at(0)] = 1;
    }
    std::reverse(first.begin(), first.end());
    std::reverse(second.begin(), second.end());
    std::reverse(third.begin(), third.end());
    std::unordered_map<int, bool> domain = {{0, false}, {1, true}, {2, false}, {3, false}, {4, false}, {5, false}, {6, false}, {7, false}, {8, false}, {9, false}};

    cryptHelper(first, second, third, res, domain, 0, 0, 0);
}
std::unordered_map<char, int> getSymbols(const std::string &first, const std::string &second, const std::string &third)
{
    std::unordered_map<char, int> map;
    for (const char &character : first)
    {
        map[character] = -1;
    }
    for (const char &character : second)
    {
        map[character] = -1;
    }
    for (const char &character : third)
    {
        map[character] = -1;
    }
    return map;
}
int main()
{
    std::string first = "TWO";
    std::string second = "TWO";
    std::string third = "FOUR";

    std::unordered_map<char, int> map = getSymbols(first, second, third);
    crypt(first, second, third, map);

    for (auto iter : map)
    {
        std::cout << iter.first << " " << iter.second << std::endl;
    }

    return 0;
}

//   T W O
//   T W O
// --------
// F O U R
// --------