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
    int checkRow(const size_t &index, const bool &player)
    {
        int score = 0;
        for (int i = 0; i < dimension; i++)
        {
            if (player && board[index][i].state == State::CROSS)
                score++;

            else if (!player && board[index][i].state == State::ZERO)
                --score;
        }
        return score;
    }
    int checkColumn(const size_t &index, const bool &player)
    {
        int score = 0;
        for (int i = 0; i < dimension; i++)
        {
            if (player && board[i][index].state == State::CROSS)
                score++;

            else if (!player && board[i][index].state == State::ZERO)
                --score;
        }
        return score;
    }
    int checkPrincipleDiagonal(const bool &player)
    {
        int score = 0;
        for (int i = 0; i < dimension; i++)
        {
            if (player && board[i][i].state == State::CROSS)
                ++score;
            else if (!player && board[i][i].state == State::ZERO)
                --score;
        }
        return score;
    }
    int checkAntiDiagonalScore(const bool &player)
    {
        int score = 0;
        for (int i = 0; i < dimension; i++)
        {
            if (player && board[i][dimension - i - 1].state == State::CROSS)
                ++score;
            else if (!player && board[i][dimension - i - 1].state == State::ZERO)
                --score;
        }
        return score;
    }
    int calculateScore(const bool &player)
    {
        for (int i = 0; i < dimension; i++)
        {
            int rowScore = checkRow(i, player);
            int columnScore = checkColumn(i, player);
            int principleDiagonalScore = checkPrincipleDiagonal(player);
            int antiDiagonalScore = checkAntiDiagonalScore(player);

            if (rowScore == -dimension || columnScore == -dimension || principleDiagonalScore == -dimension || antiDiagonalScore == -dimension)
                return -1;
            if (rowScore == dimension || columnScore == dimension || principleDiagonalScore == dimension || antiDiagonalScore == dimension)
                return 1;
        }
        return 0;
    }
    int minimax(const bool &maximizing, int depth)
    {
        int score = calculateScore(maximizing);
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
                return bestScore*(depth + 1);
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
                return bestScore*(depth + 1);
            }
        }
    }
    void play()
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
                    int score = minimax(false, 8);
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
    board.play();
    board.displayBoard();

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
