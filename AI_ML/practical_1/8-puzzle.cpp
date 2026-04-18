#include <iostream>
#include <vector>
#include <queue>

class Puzzle
{
private:
    std::vector<std::vector<int>> initialState;
    std::vector<std::vector<int>> goalState;

public:
    Puzzle()
    {
        initialState = {
            {1, 2, 3},
            {5, 0, 6},
            {7, 8, 4}};
        goalState = {
            {1, 2, 3},
            {5, 8, 6},
            {7, 4, 0}};
        // initialState.resize(3);
        // goalState.resize(3);

        // for (int i = 0; i < 3; i++)
        // {
        //     initialState[i] = std::vector<int>(3, 0);
        //     goalState[i] = std::vector<int>(3, 0);
        //     for (int j = 0; j < 3; j++)
        //     {
        //         int initial, final;
        //         std::cout << "Enter integer at position " << (3 * i) + j << " in the initial board : ";
        //         std::cin >> initial;
        //         std::cout << "Enter integer at position " << (3 * i) + j << " in the final board : ";
        //         std::cin >> final;

        //         initialState[i][j] = initial;
        //         goalState[i][j] = final;
        //     }
        // }
    }
    int calculateHeuristic(const std::vector<std::vector<int>> &state)
    {
        int score = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (state[i][j] != goalState[i][j])
                    score += 1;
            }
        }
        return score;
    }
    bool moveLeft(const std::pair<int, std::pair<int, int>> &pos)
    {
        return pos.second.second - 1 >= 0;
    }
    bool moveRight(const std::pair<int, std::pair<int, int>> &pos)
    {
        return pos.second.second + 1 <= 2;
    }
    bool moveUp(const std::pair<int, std::pair<int, int>> &pos)
    {
        return pos.second.first - 1 >= 0;
    }
    bool moveDown(const std::pair<int, std::pair<int, int>> &pos)
    {
        return pos.second.first + 1 <= 2;
    }
    void play()
    {
        std::priority_queue<
            std::pair<int, std::pair<int, int>>,
            std::vector<std::pair<int, std::pair<int, int>>>,
            std::greater<std::pair<int, std::pair<int, int>>>>
            queue;
        int score = calculateHeuristic(initialState);
        int bestI, bestJ;
        queue.emplace(score, std::make_pair<int, int>(1, 1));
        while (score != 0)
        {
            std::pair<int, std::pair<int, int>> pos = queue.top();
            std::cout << pos.second.first << " " << pos.second.second << std::endl;
            queue.pop();
            if (moveUp(pos))
            {
                std::swap(initialState[pos.second.first - 1][pos.second.second], initialState[pos.second.first][pos.second.second]);
                int tempScore = calculateHeuristic(initialState);
                if (tempScore < score)
                {
                    score = tempScore;
                    std::pair<int, int> newPos = {pos.second.first - 1, pos.second.second};
                    queue.emplace(score, newPos);
                    std::cout << newPos.first << " " << newPos.second << std::endl;
                }
                else
                    std::swap(initialState[pos.second.first - 1][pos.second.second], initialState[pos.second.first][pos.second.second]);
            }
            if (moveDown(pos))
            {
                std::swap(initialState[pos.second.first + 1][pos.second.second], initialState[pos.second.first][pos.second.second]);
                int tempScore = calculateHeuristic(initialState);
                if (tempScore < score)
                {
                    score = tempScore;
                    std::pair<int, int> newPos = {pos.second.first + 1, pos.second.second};
                    queue.emplace(score, newPos);
                    std::cout << newPos.first << " " << newPos.second << std::endl;
                }
                else
                    std::swap(initialState[pos.second.first + 1][pos.second.second], initialState[pos.second.first][pos.second.second]);
            }
            if (moveLeft(pos))
            {
                std::swap(initialState[pos.second.first][pos.second.second - 1], initialState[pos.second.first][pos.second.second]);
                int tempScore = calculateHeuristic(initialState);
                if (tempScore < score)
                {
                    score = tempScore;
                    std::pair<int, int> newPos = {pos.second.first, pos.second.second - 1};
                    queue.emplace(score, newPos);
                    std::cout << newPos.first << " " << newPos.second << std::endl;
                }
                else
                    std::swap(initialState[pos.second.first][pos.second.second - 1], initialState[pos.second.first][pos.second.second]);
            }
            if (moveRight(pos))
            {
                std::swap(initialState[pos.second.first][pos.second.second + 1], initialState[pos.second.first][pos.second.second]);
                int tempScore = calculateHeuristic(initialState);
                if (tempScore < score)
                {
                    score = tempScore;
                    std::pair<int, int> newPos = {pos.second.first, pos.second.second + 1};
                    queue.emplace(score, newPos);
                    std::cout << newPos.first << " " << newPos.second << std::endl;
                }
                else
                    std::swap(initialState[pos.second.first][pos.second.second + 1], initialState[pos.second.first][pos.second.second]);
            }
        }
    }
    void display()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                std::cout << initialState[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};
int main()
{
    Puzzle p;
    p.play();
    p.display();
    return 0;
}
/*
[
    [0,1,2],
    [3,4,5],
    [6,7,8]
]
*/