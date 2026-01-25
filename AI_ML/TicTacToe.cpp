#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <limits>

enum States
{
    BLANCK,
    CROSS,
    ZERO
};
enum Location
{
    LEFT_CORNER,
    RIGHT_CORNER,
    MIDDLE
};
enum Diagonal
{
    PRINCIPLE = 4,
    ANTI = 2
};

struct Cell
{
    States state;
    Location loc;
};
class TicTacToe
{
private:
    std::vector<Cell> board;
    // 0 -> me
    // 1 -> computer
    bool turn;

public:
    TicTacToe()
    {
        board.resize(9);
        turn = true;

        bool isCorner = true;

        for (int i = 0; i < 9; i++)
        {
            // if (i != 4)
            {
                bool isLeft = !(i % 3);
                Cell cell;
                cell.state = States::BLANCK;
                cell.loc = isCorner ? isLeft ? Location::LEFT_CORNER : Location::RIGHT_CORNER : Location::MIDDLE;

                board[i] = cell;
            }
            isCorner = !isCorner;
        }
    }
    bool isFull()
    {
        auto state = std::find_if(board.begin(), board.end(), [](const Cell &val)
                                  { return val.state == States::BLANCK; });
        return state == board.end();
    }
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
    void play()
    {
        while (!isFull())
        {
            size_t minIndex = 4;
            int minScore = 0;
            for (int i = 0; i < 9; i++)
            {
                if (board[i].state == States::BLANCK)
                {
                    std::unordered_map<int, int> scoreRow = traverseRow(board[i], i, turn);
                    std::unordered_map<int, int> scoreColumn = traverseColumn(board[i], i, turn);
                    std::unordered_map<int, int> scoreDiagonal = traverseDiagonal(board[i], i, turn);

                    int score;
                    if (turn)
                        score = scoreRow[!turn] < scoreColumn[!turn] ? scoreRow[!turn] < scoreDiagonal[!turn] ? scoreRow[!turn] : scoreDiagonal[!turn] : scoreColumn[!turn] < scoreDiagonal[!turn] ? scoreColumn[!turn]
                                                                                                                                                                                                   : scoreDiagonal[!turn];
                    else
                        score = scoreRow[turn] < scoreColumn[turn] ? scoreRow[turn] < scoreDiagonal[turn] ? scoreRow[turn] : scoreDiagonal[turn] : scoreColumn[turn] < scoreDiagonal[turn] ? scoreColumn[turn]
                                                                                                                                                                                                   : scoreDiagonal[turn];
                    if (score < minScore)
                    {
                        minScore = score;
                        minIndex = i;
                    }
                }
            }
            board[minIndex].state = turn ? States::CROSS : board[minIndex].state;
            board[minIndex].state = !turn ? States::ZERO : board[minIndex].state;
            // std::cout << "INDEX: " << minIndex << " TURN: " << (turn ? "CROSS" : "ZERO") << std::endl;
            
            turn = !turn;
        }
    }

    void displayBoard()
    {
        for (int i = 0; i < 3;i++){
            std::cout << "| ";
            for (int j = 0; j < 3; j++)
            {
                std::cout << (board[3 * i + j].state == States::CROSS ? 'X' : 'O') << " | ";
            }
            std::cout << std::endl;
        }
    }
};
int main()
{
    TicTacToe board;
    board.play();
    board.displayBoard();

    return 0;
}