#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

// Various possible states of a cell in Tic-Tac-Toe
enum States
{
    BLANK,
    CROSS,
    ZERO
};

// NOT NECCESSARY
enum Location
{
    LEFT_CORNER,
    RIGHT_CORNER,
    MIDDLE
};

// Distance between indices of each element of a diagonal
enum Diagonal
{
    PRINCIPLE = 4,
    ANTI = 2
};

// Custom data type for a cell of a tic tac toe board
struct Cell
{
    States state;
    Location loc;
};

// Blueprint for the solution of TicTacToe problem
class TicTacToe
{
private:
    std::vector<Cell> board; // TicTacToe board
    // 0 -> ZERO
    // 1 -> CROSS
    bool turn;

public:
    // Default constructor
    TicTacToe()
    {
        board.resize(9); // intialize the board size to 9
        turn = true;     // CROSS's turn

        // tracks whether the cell is in corner or not (NOT NECCESSARY)
        bool isCorner = true;

        // Generate a random number
        srand(time(0));
        int randomInt = random() % 9;

        // Assign location and BLANK state to each cell
        for (int i = 0; i < 9; i++)
        {
            bool isLeft = !(i % 3);
            Cell cell;
            cell.state = States::BLANK;

            if (i == randomInt)
                cell.state = States::ZERO;
            cell.loc = isCorner ? isLeft ? Location::LEFT_CORNER : Location::RIGHT_CORNER : Location::MIDDLE;
            board[i] = cell;
            isCorner = !isCorner;
        }
    }
    /**
     * @brief check whether any cell on the board is blank
     * @param NA
     * @return ture (if any cell is BLANK)
     */
    inline bool isFull()
    {
        auto state = std::find_if(board.begin(), board.end(), [](const Cell &val)
                                  { return val.state == States::BLANK; });
        return state == board.end();
    }
    /**
     * @brief traverse a given column and calculate the score of oponent and the player
     * @param cell (Cell)
     * @param index (int) index of the cell on the board
     * @param turn (bool) indicates whose turn it is to play
     * @returns scores (unordered_map<int,int>)
     */
    std::unordered_map<int, int> traverseColumn(const Cell &cell, const size_t &index, const bool &turn)
    {
        std::unordered_map<int, int> score;
        score.insert({turn, 0});
        score.insert({!turn, 0});

        size_t iter = index;
        do
        {
            iter = (iter + 3);
            iter = iter > 8 ? iter % 3 : iter;

            if (turn && board[iter].state == States::CROSS)
                score.at(turn)++;
            else if (turn && board[iter].state == States::ZERO)
                score.at(!turn)--;
            if (!turn && board[iter].state == States::ZERO)
                score.at(!turn)++;
            else if (!turn && board[iter].state == States::CROSS)
                score.at(turn)--;
        } while (iter != index);
        return score;
    }

    /**
     * @brief traverses a given row and calculates score of the player and the opponent
     * @param cell (Cell)
     * @param index (int) index of the cell on the board
     * @param turn (bool) indicates whose turn it is to play.
     * @returns score (unordered_map<int,int>)
     */
    std::unordered_map<int, int> traverseRow(const Cell &cell, const size_t index, const bool &turn)
    {
        std::unordered_map<int, int> score;
        score.insert({turn, 0});
        score.insert({!turn, 0});

        std::vector<std::unordered_set<int>> rows = {
            {0, 1, 2},
            {3, 4, 5},
            {6, 7, 8}};

        const auto &row = std::find_if(rows.begin(), rows.end(), [&index](const std::unordered_set<int> &val)
                                       {
            if(val.find(index) != val.end())
                return true;
            return false; });
        if (row != rows.end())
        {
            for (int iter : *(row))
            {
                if (iter != index)
                {
                    if (turn && board[iter].state == States::CROSS)
                        score.at(turn)++;
                    else if (turn && board[iter].state == States::ZERO)
                        score.at(!turn)--;
                    if (!turn && board[iter].state == States::ZERO)
                        score.at(!turn)++;
                    else if (!turn && board[iter].state == States::CROSS)
                        score.at(turn)--;
                }
            }
        }
        return score;
    }
    /**
     * @brief traverses a given diagonal and calculates score of the player and the opponent
     * @param cell (Cell)
     * @param index (int) index of the cell on the board
     * @param turn (bool) indicates whose turn it is to play.
     * @returns score (unordered_map<int,int>)
     */
    std::unordered_map<int, int> traverseDiagonal(const Cell &cell, const size_t index, const bool &turn)
    {
        std::unordered_map<int, int> score;
        score.insert({turn, 0});
        score.insert({!turn, 0});

        size_t iter = index;

        if (index == 4)
        {
            std::vector<int> diagonalElements = {0, 2, 6, 8};
            for (int &ele : diagonalElements)
            {
                if (turn && board[ele].state == States::CROSS)
                    score.at(turn)++;
                else if (turn && board[ele].state == States::ZERO)
                    score.at(!turn)--;
                if (!turn && board[ele].state == States::ZERO)
                    score.at(!turn)++;
                else if (!turn && board[ele].state == States::CROSS)
                    score.at(turn)--;
            }
        }
        else if ((cell.loc == Location::LEFT_CORNER || cell.loc == Location::RIGHT_CORNER) && (index == 0 || index == 8))
        {
            do
            {
                iter = (iter + Diagonal::PRINCIPLE);
                iter = iter > 8 ? iter % Diagonal::PRINCIPLE : iter;

                if (turn && board[iter].state == States::CROSS)
                    score.at(turn)++;
                else if (turn && board[iter].state == States::ZERO)
                    score.at(!turn)--;
                if (!turn && board[iter].state == States::ZERO)
                    score.at(!turn)++;
                else if (!turn && board[iter].state == States::CROSS)
                    score.at(turn)--;

            } while (iter != index);
        }
        else if ((cell.loc == Location::LEFT_CORNER || cell.loc == Location::RIGHT_CORNER) && index == 2)
        {
            do
            {
                iter = (iter + Diagonal::ANTI);

                if (turn && board[iter].state == States::CROSS)
                    score.at(turn)++;
                else if (turn && board[iter].state == States::ZERO)
                    score.at(!turn)--;
                if (!turn && board[iter].state == States::ZERO)
                    score.at(!turn)++;
                else if (!turn && board[iter].state == States::CROSS)
                    score.at(turn)--;

            } while (iter < index);
        }
        else if ((cell.loc == Location::LEFT_CORNER || cell.loc == Location::RIGHT_CORNER) && index == 6)
        {
            do
            {
                iter = (iter - Diagonal::ANTI);

                if (turn && board[iter].state == States::CROSS)
                    score.at(turn)++;
                else if (turn && board[iter].state == States::ZERO)
                    score.at(!turn)--;
                if (!turn && board[iter].state == States::ZERO)
                    score.at(!turn)++;
                else if (!turn && board[iter].state == States::CROSS)
                    score.at(turn)--;

            } while (iter > 2);
        }
        return score;
    }

    /**
     * @brief plays the game
     * @param NA
     * @returns NA
     * @details While the board has empty cells do:
     * calculate the possible score at each cell of the board for the player and the opponent.
     * Change the state of that cell which has the maximum score for the opponent (to prevent the opponent from wining)
     * If the score of any cell for the player is 3 then terminate the loop. (player has won)
     */
    void play()
    {
        while (!isFull())
        {
            size_t minIndex;
            size_t maxIndex;

            int maxScore = 0;
            int minScore = 0;

            for (int i = 0; i < 9; i++)
            {
                if (board[i].state == States::BLANK)
                {
                    std::unordered_map<int, int> scoreRow = traverseRow(board[i], i, turn);
                    std::unordered_map<int, int> scoreColumn = traverseColumn(board[i], i, turn);
                    std::unordered_map<int, int> scoreDiagonal = traverseDiagonal(board[i], i, turn);

                    int score, winScore;

                    // calculate score for the opponent
                    if (turn)
                        score = scoreRow[!turn] < scoreColumn[!turn] ? scoreRow[!turn] < scoreDiagonal[!turn] ? scoreRow[!turn] : scoreDiagonal[!turn] : scoreColumn[!turn] < scoreDiagonal[!turn] ? scoreColumn[!turn]
                                                                                                                                                                                                   : scoreDiagonal[!turn];
                    else
                        score = scoreRow[turn] < scoreColumn[turn] ? scoreRow[turn] < scoreDiagonal[turn] ? scoreRow[turn] : scoreDiagonal[turn] : scoreColumn[turn] < scoreDiagonal[turn] ? scoreColumn[turn]
                                                                                                                                                                                           : scoreDiagonal[turn];

                    // calculate score for the player
                    if (turn)
                        winScore = scoreRow[turn] > scoreColumn[turn] ? scoreRow[turn] > scoreDiagonal[turn] ? scoreRow[turn] : scoreDiagonal[turn] : scoreColumn[turn] > scoreDiagonal[turn] ? scoreColumn[turn]
                                                                                                                                                                                              : scoreDiagonal[turn];
                    else
                        winScore = scoreRow[!turn] > scoreColumn[turn] ? scoreRow[!turn] > scoreDiagonal[!turn] ? scoreRow[!turn] : scoreDiagonal[!turn] : scoreColumn[!turn] > scoreDiagonal[!turn] ? scoreColumn[!turn]
                                                                                                                                                                                                     : scoreDiagonal[turn];
                    if (score < minScore)
                    {
                        minScore = score;
                        minIndex = i;
                    }
                    if (winScore > maxScore)
                    {
                        maxScore = winScore;
                        maxIndex = i;
                    }
                }
            }
            // Winning condition
            if (maxScore + 1 == 3)
            {
                board[maxIndex].state = turn ? States::CROSS : board[maxIndex].state;
                board[maxIndex].state = !turn ? States::ZERO : board[maxIndex].state;
                std::cout << (turn ? "X WINS THE GAME" : "O WINS THE GAME") << std::endl
                          << std::endl;
                break;
            }
            // change the state
            board[minIndex].state = turn ? States::CROSS : board[minIndex].state;
            board[minIndex].state = !turn ? States::ZERO : board[minIndex].state;

            // Line for debugging 😊
            // std::cout << "MIN INDEX: " << minIndex << " STATE: " << (board[minIndex].state == States::CROSS ? 'X' : 'O') << std::endl;

            turn = !turn;
        }
    }

    /**
     * @brief Displays state of the entire board
     * @param NA
     * @returns NA
     */
    void displayBoard()
    {
        for (int i = 0; i < 3; i++)
        {
            std::cout << "| ";
            for (int j = 0; j < 3; j++)
            {
                // std::cout << (board[3 * i + j].state == States::CROSS ? 'X' : 'O') << " | ";
                int index = 3 * i + j;
                if (board[index].state == States::CROSS)
                    std::cout << "\x1b[1m" << 'X' << " | ";
                else if (board[index].state == States::ZERO)
                    std::cout << 'O' << " | ";
                else
                    std::cout << "\x1b[1m" << ' ' << " | ";
            }
            std::cout << std::endl;
        }
    }
};
int main()
{
    // Instantiate the board
    TicTacToe board;

    // play
    board.play();

    // display
    board.displayBoard();

    return 0;
}