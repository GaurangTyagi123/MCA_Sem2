#include <iostream>
#include <vector>
#include <climits>

enum State
{
    BLANK,
    CROSS,
    ZERO
};
struct Cell
{
    State state;
};

class TicTacToe
{
private:
    std::vector<std::vector<Cell>> board;
    const size_t dimension = 3;

public:
    TicTacToe()
    {
        board.resize(dimension);
        for (int i = 0; i < dimension; i++)
        {
            board[i].resize(dimension);
            for (int j = 0; j < dimension; j++)
            {
                Cell cell;
                cell.state = State::BLANK;
                board[i][j] = cell;
            }
        }
    }
    bool isFull()
    {
        for (int i = 0; i < dimension; i++)
        {
            for (int j = 0; j < dimension; j++)
            {
                if (board[i][j].state == State::BLANK)
                    return false;
            }
        }
        return true;
    }
    int checkRow(const size_t &index)
    {
        int score_cross = 0;
        int score_zero = 0;
        for (int i = 0; i < dimension; i++)
        {
            if (board[index][i].state == State::CROSS)
                score_cross++;

            else if (board[index][i].state == State::ZERO)
                --score_zero;
        }
        if (score_cross == 3)
            return score_cross;
        else if (score_zero == -3)
            return score_zero;
        else
            return 0;
    }
    int checkColumn(const size_t &index)
    {
        int score_cross = 0;
        int score_zero = 0;
        for (int i = 0; i < dimension; i++)
        {
            if (board[i][index].state == State::CROSS)
                score_cross++;

            else if (board[i][index].state == State::ZERO)
                --score_zero;
        }
        if (score_cross == 3)
            return score_cross;
        else if (score_zero == -3)
            return score_zero;
        else
            return 0;
    }
    int checkPrincipleDiagonal()
    {
        int score_cross = 0;
        int score_zero = 0;
        for (int i = 0; i < dimension; i++)
        {
            if (board[i][i].state == State::CROSS)
                ++score_cross;
            else if (board[i][i].state == State::ZERO)
                --score_zero;
        }
        if (score_cross == 3)
            return score_cross;
        else if (score_zero == -3)
            return score_zero;
        else
            return 0;
    }
    int checkAntiDiagonalScore()
    {
        int score_cross = 0;
        int score_zero = 0;
        for (int i = 0; i < dimension; i++)
        {
            if (board[i][dimension - i - 1].state == State::CROSS)
                ++score_cross;
            else if (board[i][dimension - i - 1].state == State::ZERO)
                --score_zero;
        }
        if (score_cross == 3)
            return score_cross;
        else if (score_zero == -3)
            return score_zero;
        else
            return 0;
    }
    int calculateScore()
    {
        for (int i = 0; i < dimension; i++)
        {
            int rowScore = checkRow(i);
            int columnScore = checkColumn(i);
            int principleDiagonalScore = checkPrincipleDiagonal();
            int antiDiagonalScore = checkAntiDiagonalScore();

            if (rowScore == -dimension || columnScore == -dimension || principleDiagonalScore == -dimension || antiDiagonalScore == -dimension)
                return -1;
            if (rowScore == dimension || columnScore == dimension || principleDiagonalScore == dimension || antiDiagonalScore == dimension)
                return 1;
        }
        return 0;
    }
    int dfs(const bool &player, int depth)
    {
        int score = calculateScore();
        if (score != 0 || isFull())
        {
            return score;
        }
        else
        {
            if (player)
            {
                int bestScore;
                for (int i = 0; i < dimension; i++)
                {
                    for (int j = 0; j < dimension; j++)
                    {
                        if (board[i][j].state == State::BLANK)
                        {
                            board[i][j].state = State::CROSS;
                            int tempScore = dfs(false, depth - 1);
                            bestScore = tempScore;
                            board[i][j].state = State::BLANK;
                        }
                    }
                }
                return bestScore;
            }
            else
            {
                int bestScore;
                for (int i = 0; i < dimension; i++)
                {
                    for (int j = 0; j < dimension; j++)
                    {
                        if (board[i][j].state == State::BLANK)
                        {
                            board[i][j].state = State::ZERO;
                            int tempScore = dfs(true, depth - 1);
                            bestScore = tempScore;
                            board[i][j].state = State::BLANK;
                        }
                    }
                }
                return bestScore;
            }
        }
    }
    bool playUser()
    {
        size_t cellIndex = 0;
        std::cout << "Enter a cell number (1-9): ";
        std::cin >> cellIndex;

        size_t indexJ = cellIndex % dimension;
        size_t indexI = (cellIndex - indexJ) / dimension;

        if (board[indexI][indexJ].state == State::BLANK)
            board[indexI][indexJ].state = State::ZERO;
        return false;
    }
    bool play()
    {
        int bestScore = 0;
        int bestI = -1, bestJ = -1;

        for (int i = 0; i < dimension; i++)
        {
            for (int j = 0; j < dimension; j++)
            {
                if (board[i][j].state == State::BLANK)
                {
                    board[i][j].state = State::CROSS;
                    int score = dfs(false, 9);
                    board[i][j].state = State::BLANK;
                    if (score > 0)
                    {
                        bestScore = score;
                        bestI = i;
                        bestJ = j;
                    }
                }
            }
        }
        if(bestScore == 0){
            std::cout << "O has won the game" << std::endl;
            return true;
        }
        if (bestI != -1 && bestJ != -1)
            board[bestI][bestJ].state = State::CROSS;
        return false;
    }

    void displayBoard()
    {
        for (int i = 0; i < dimension; i++)
        {
            for (int j = 0; j < dimension; j++)
            {
                const Cell &cell = board[i][j];
                if (cell.state == State::CROSS)
                    std::cout << "| X |";
                else if (cell.state == State::ZERO)
                    std::cout << "| O |";
                else
                    std::cout << "|   |";
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    TicTacToe board;
    bool hasWon = false;
    do
    {
        hasWon = board.play();
        board.displayBoard();
        if(hasWon)
            break;
        hasWon = board.playUser();
        board.displayBoard();
        if(hasWon)
        break;
        std::cout << "---------------" << std::endl;
    } while (!board.isFull());

    return 0;
}
