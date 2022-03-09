/*
 * @lc app=leetcode id=1926 lang=cpp
 *
 * [1926] Nearevec Exit from Entrance in Maze
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=vecart
class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        int width = maze[0].size();
        int height = maze.size();
        queue<int> vec;
        int count = 0;
        maze[entrance[0]][entrance[1]] = '+';
        if ((entrance[1] -= 1) >= 0 && maze[entrance[0]][entrance[1]] == '.')
            vec.push(entrance[0] * 128 + entrance[1]);
        if ((entrance[1] += 2) < width && maze[entrance[0]][entrance[1]] == '.')
            vec.push(entrance[0] * 128 + entrance[1]);
        --entrance[1];
        if ((entrance[0] -= 1) >= 0 && maze[entrance[0]][entrance[1]] == '.')
            vec.push(entrance[0] * 128 + entrance[1]);
        if ((entrance[0] += 2) < height && maze[entrance[0]][entrance[1]] == '.')
            vec.push(entrance[0] * 128 + entrance[1]);

        while (!vec.empty())
        {
            ++count;
            auto len = vec.size();
            while (len--)
            {
                auto &val = vec.front();
                auto x = val / 128, y = val % 128;
                vec.pop();
                if (maze[x][y] == '+')
                {
                    continue;
                }
                if (x == 0 || x == height - 1 || y == 0 || y == width - 1)
                {
                    return count;
                }
                maze[x][y] = '+';
                --y;
                if (maze[x][y] == '.')
                    vec.push(x * 128 + y);
                y += 2;
                if (maze[x][y] == '.')
                    vec.push(x * 128 + y);
                --y;
                x -= 1;
                if (maze[x][y] == '.')
                    vec.push(x * 128 + y);
                x += 2;
                if (maze[x][y] == '.')
                    vec.push(x * 128 + y);
            }
        }
        return -1;
    }
};
// @lc code=end