#include <iostream>

// Blueprint for WaterJug Problem
class WaterJug
{
private:
    int bigJug; // quantity of liquid currently in big jug
    int smallJug; // quantity of liquid currently in small jug
    int bigJugCapacity; // total capacity of big jug
    int smallJugCapacity; // total capacity of small jug

public:
    // Default constructor
    WaterJug() : bigJug(0), smallJug(0), bigJugCapacity(0), smallJugCapacity(0) {}

    // Parameter constuctor
    // Initializes the jugs' total capacity according to user provided values
    WaterJug(int big, int small) : bigJug(0), smallJug(0), bigJugCapacity(big), smallJugCapacity(small) {}

    /**
     * @brief Completely fill the big jug
     * @return NA
     * @param NA
     * @details Completely fills the jug only if the jug is empty
     */
    void fillBigJug()
    {
        if (bigJug == 0)
            bigJug = bigJugCapacity;
    }

    /**
     * @brief Transfer the liquid in big jug to small jug
     * @param NA
     * @returns NA
     * @details If the big jug is not empty then
     * 1. check if the big jug has more liquid than the total capacity of small jug.
     * 2. if it is then completely fill the small jug and keep the extra liquid in the big jug
     * 3. if it is not then completely transfer the contents of big jug to small jug
     */
    void transferToSmall()
    {
        if (bigJug > 0)
        {
            if (bigJug > smallJugCapacity)
            {
                int diff = smallJugCapacity - smallJug;
                bigJug = bigJug - diff;
                smallJug = smallJug + diff;
            }
            else
            {
                smallJug = smallJug + bigJug;
                bigJug = 0;
            }
        }
    }
    /**
     * @brief Empty the small jug
     * @param NA
     * @return NA
     */
    void emptySmall()
    {
        {
            if (smallJug > 0)
            {
                smallJug = 0;
            }
        }
    }
    /**
     * @brief Fill the jug upto limit (limit)
     * @param limit : int (amount upto which the jug is to be filled)
     * @return NA
     * @details While the big jug is not filled upto the limit do
     * 1.) check if the big jug is empty then fill the big jug completely
     * 2.) check if big jug is filled but the small jug is empty then transfer the contents of big jug to small jug
     * 3.) check if big jug is filled and the small jug is completely filled then empty the small jug
     * 4.) check if big jug is filled and the small jug is also filled but not completely then transfer from big to small jug
     */
    void play(int limit)
    {
        while (bigJug != limit)
        {
            std::cout << "BIG JUG: " << bigJug << "L  SMALL JUG: " << smallJug <<"L"<< std::endl;
            if (bigJug == 0 && smallJug == 0)
            {
                fillBigJug();
            }
            else if (bigJug == 0 && smallJug > 0)
            {
                fillBigJug();
            }
            else if (bigJug > 0 && smallJug == 0)
            {
                transferToSmall();
            }
            else if (bigJug > 0 && smallJug == smallJugCapacity)
            {
                emptySmall();
            }
            else if (bigJug > 0 && smallJug > 0)
            {
                transferToSmall();
            }
        }
        std::cout << "BIG JUG: " << bigJug << "L SMALL JUG: " << smallJug <<"L"<< std::endl;
    }
};
int main()
{
    // variable declaration
    size_t bigJugSize, smallJugSize, playSize;

    std::cout << "Enter Big Jug Size: ";
    std::cin >> bigJugSize;

    std::cout << "Enter Small Jug Size: ";
    std::cin >> smallJugSize;

    std::cout << "Enter play size: ";
    std::cin >> playSize;

    // Instantiate the water jug object
    WaterJug wj(bigJugSize, smallJugSize);
    if(bigJugSize > 0 && smallJugSize > 0) {
        wj.play(playSize);
    }
    else
        std::cout << "Enter valid jug sizes" << std::endl;

    return 0;
}