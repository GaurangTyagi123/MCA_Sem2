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
    int minimax(const bool &maximizing, int depth)
    {
        int score = calculateScore();
        if (score != 0 || isFull())
        {
            return score;
        }
        else
        {
            if (maximizing)
            {
                int bestScore = INT_MIN;
                for (int i = 0; i < dimension; i++)
                {
                    for (int j = 0; j < dimension; j++)
                    {
                        if (board[i][j].state == State::BLANK)
                        {
                            board[i][j].state = State::CROSS;
                            int tempScore = minimax(false, depth - 1);
                            bestScore = std::max(bestScore, tempScore);
                            board[i][j].state = State::BLANK;
                        }
                    }
                }
                return bestScore;
            }
            else
            {
                int bestScore = INT_MAX;
                for (int i = 0; i < dimension; i++)
                {
                    for (int j = 0; j < dimension; j++)
                    {
                        if (board[i][j].state == State::BLANK)
                        {
                            board[i][j].state = State::ZERO;
                            int tempScore = minimax(true, depth - 1);
                            bestScore = std::min(bestScore, tempScore);
                            board[i][j].state = State::BLANK;
                        }
                    }
                }
                return bestScore;
            }
        }
    }
    std::pair<size_t, size_t> playUser()
    {
        size_t cellIndex = 0;
        std::cout << "Enter a cell number (1-9): ";
        std::cin >> cellIndex;

        size_t indexJ = cellIndex % dimension;
        size_t indexI = (cellIndex - indexJ) / dimension;

        if (board[indexI][indexJ].state == State::BLANK)
            board[indexI][indexJ].state = State::ZERO;
        std::pair<size_t, size_t> p = {indexI, indexJ};
        return p;
    }
    std::pair<size_t, size_t> play()
    {
        int bestScore = INT_MIN;
        int bestI = -1, bestJ = -1;

        for (int i = 0; i < dimension; i++)
        {
            for (int j = 0; j < dimension; j++)
            {
                if (board[i][j].state == State::BLANK)
                {
                    board[i][j].state = State::CROSS;
                    int score = minimax(false, 9);
                    board[i][j].state = State::BLANK;

                    if (score > bestScore)
                    {
                        bestScore = score;
                        bestI = i;
                        bestJ = j;
                    }
                }
            }
        }
        board[bestI][bestJ].state = State::CROSS;
        std::pair<size_t, size_t> p = {bestI, bestJ};
        return p;
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

    do
    {
        board.play();
        board.displayBoard();
        board.playUser();
    } while (!board.isFull());

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <climits>

// enum State
// {
//     BLANK,
//     CROSS,
//     ZERO
// };

// struct Cell
// {
//     State state = BLANK;
// };

// class TicTacToe
// {
// private:
//     static constexpr int N = 3;
//     std::vector<std::vector<Cell>> board;

// public:
//     TicTacToe() : board(N, std::vector<Cell>(N)) {}

//     bool isFull() const
//     {
//         for (auto &row : board)
//             for (auto &c : row)
//                 if (c.state == BLANK)
//                     return false;
//         return true;
//     }

//     /* ---------- EVALUATION (FIXED PERSPECTIVE: X) ---------- */

//     int evaluate() const
//     {
//         // rows & columns
//         for (int i = 0; i < N; i++)
//         {
//             int r = 0, c = 0;
//             for (int j = 0; j < N; j++)
//             {
//                 r += (board[i][j].state == CROSS) - (board[i][j].state == ZERO);
//                 c += (board[j][i].state == CROSS) - (board[j][i].state == ZERO);
//             }
//             if (r == N || c == N)
//                 return 1;
//             if (r == -N || c == -N)
//                 return -1;
//         }

//         // diagonals
//         int d1 = 0, d2 = 0;
//         for (int i = 0; i < N; i++)
//         {
//             d1 += (board[i][i].state == CROSS) - (board[i][i].state == ZERO);
//             d2 += (board[i][N - i - 1].state == CROSS) - (board[i][N - i - 1].state == ZERO);
//         }
//         if (d1 == N || d2 == N)
//             return 1;
//         if (d1 == -N || d2 == -N)
//             return -1;

//         return 0;
//     }

//     /* -------------------- MINIMAX -------------------- */

//     int minimax(bool maximizing, int depth)
//     {
//         int score = evaluate();
//         if (score != 0)
//             return score * (depth + 1);
//         if (isFull())
//             return 0;

//         if (maximizing)
//         {
//             int best = INT_MIN;
//             for (int i = 0; i < N; i++)
//                 for (int j = 0; j < N; j++)
//                     if (board[i][j].state == BLANK)
//                     {
//                         board[i][j].state = CROSS;
//                         best = std::max(best, minimax(false, depth - 1));
//                         board[i][j].state = BLANK;
//                     }
//             return best;
//         }
//         else
//         {
//             int best = INT_MAX;
//             for (int i = 0; i < N; i++)
//                 for (int j = 0; j < N; j++)
//                     if (board[i][j].state == BLANK)
//                     {
//                         board[i][j].state = ZERO;
//                         best = std::min(best, minimax(true, depth - 1));
//                         board[i][j].state = BLANK;
//                     }
//             return best;
//         }
//     }

//     /* -------------------- AI MOVE -------------------- */

//     void play()
//     {
//         int bestScore = INT_MIN;
//         int bi = -1, bj = -1;

//         while (!isFull())
//         {
//             for (int i = 0; i < N; i++)
//                 for (int j = 0; j < N; j++)
//                     if (board[i][j].state == BLANK)
//                     {
//                         board[i][j].state = CROSS;
//                         int score = minimax(false, 8);
//                         board[i][j].state = BLANK;

//                         if (score > bestScore)
//                         {
//                             bestScore = score;
//                             bi = i;
//                             bj = j;
//                         }
//                     }

//             board[bi][bj].state = CROSS;
//         }
//     }

//     void display() const
//     {
//         for (int i = 0; i < N; i++)
//         {
//             for (int j = 0; j < N; j++)
//             {
//                 if (board[i][j].state == CROSS)
//                     std::cout << "| X ";
//                 else if (board[i][j].state == ZERO)
//                     std::cout << "| O ";
//                 else
//                     std::cout << "|   ";
//             }
//             std::cout << "|\n";
//         }
//     }
// };

// int main()
// {
//     TicTacToe game;
//     game.play();
// }
