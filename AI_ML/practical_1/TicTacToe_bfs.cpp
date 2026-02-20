#include <iostream>
#include <vector>
#include <climits>
#include <queue>

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
    int checkRow(const size_t &index, const std::vector<std::vector<Cell>> &tempBoard)
    {
        int score_cross = 0;
        int score_zero = 0;
        for (int i = 0; i < dimension; i++)
        {
            if (tempBoard[index][i].state == State::CROSS)
                score_cross++;

            else if (tempBoard[index][i].state == State::ZERO)
                --score_zero;
        }
        if (score_cross == 3)
            return score_cross;
        else if (score_zero == -3)
            return score_zero;
        else
            return 0;
    }
    int checkColumn(const size_t &index, const std::vector<std::vector<Cell>> &tempBoard)
    {
        int score_cross = 0;
        int score_zero = 0;
        for (int i = 0; i < dimension; i++)
        {
            if (tempBoard[i][index].state == State::CROSS)
                score_cross++;

            else if (tempBoard[i][index].state == State::ZERO)
                --score_zero;
        }
        if (score_cross == 3)
            return score_cross;
        else if (score_zero == -3)
            return score_zero;
        else
            return 0;
    }
    int checkPrincipleDiagonal(const std::vector<std::vector<Cell>> &tempBoard)
    {
        int score_cross = 0;
        int score_zero = 0;
        for (int i = 0; i < dimension; i++)
        {
            if (tempBoard[i][i].state == State::CROSS)
                ++score_cross;
            else if (tempBoard[i][i].state == State::ZERO)
                --score_zero;
        }
        if (score_cross == 3)
            return score_cross;
        else if (score_zero == -3)
            return score_zero;
        else
            return 0;
    }
    int checkAntiDiagonalScore(const std::vector<std::vector<Cell>> &tempBoard)
    {
        int score_cross = 0;
        int score_zero = 0;
        for (int i = 0; i < dimension; i++)
        {
            if (tempBoard[i][dimension - i - 1].state == State::CROSS)
                ++score_cross;
            else if (tempBoard[i][dimension - i - 1].state == State::ZERO)
                --score_zero;
        }
        if (score_cross == 3)
            return score_cross;
        else if (score_zero == -3)
            return score_zero;
        else
            return 0;
    }
    int calculateScore(const std::vector<std::vector<Cell>> &tempBoard)
    {
        for (int i = 0; i < dimension; i++)
        {
            int rowScore = checkRow(i, tempBoard);
            int columnScore = checkColumn(i, tempBoard);
            int principleDiagonalScore = checkPrincipleDiagonal(tempBoard);
            int antiDiagonalScore = checkAntiDiagonalScore(tempBoard);

            if (rowScore == -dimension || columnScore == -dimension || principleDiagonalScore == -dimension || antiDiagonalScore == -dimension)
                return -1;
            if (rowScore == dimension || columnScore == dimension || principleDiagonalScore == dimension || antiDiagonalScore == dimension)
                return 1;
        }
        return 0;
    }
    int bfs(const bool &player, std::queue<std::vector<std::vector<Cell>>> &qu, int depth)
    {
        bool localPlayer = player;
        while (!qu.empty())
        {
            std::vector<std::vector<Cell>> tempBoard = qu.front();
            qu.pop();
            int score = calculateScore(tempBoard);
            if (score > 0)
                return score;

                for (int i = 0; i < dimension; i++)
                {
                    for (int j = 0; j < dimension; j++)
                    {
                        if (tempBoard[i][j].state == State::BLANK)
                        {
                            if(localPlayer){
                                tempBoard[i][j].state = State::CROSS;
                                localPlayer = !localPlayer;
                            }
                            else{
                                tempBoard[i][j].state = State::ZERO;
                                localPlayer = !localPlayer;
                            }
                            qu.push(tempBoard);
                        }
                    }
                }
        }
        return 0;
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
        std::queue<std::vector<std::vector<Cell>>> qu;

        for (int i = 0; i < dimension; i++)
        {
            for (int j = 0; j < dimension; j++)
            {
                if (board[i][j].state == State::BLANK)
                {
                    board[i][j].state = State::CROSS;
                    qu.push(board);
                    int score = bfs(false, qu, 9);
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
        if (bestScore == 0)
        {
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
        if (hasWon)
            break;
        hasWon = board.playUser();
        board.displayBoard();
        if (hasWon)
            break;
        std::cout << "---------------" << std::endl;
    } while (!board.isFull());

    return 0;
}
