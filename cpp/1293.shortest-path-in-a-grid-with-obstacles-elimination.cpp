/*
 * @lc app=leetcode id=1293 lang=cpp
 *
 * [1293] Shortest Path in a Grid with Obstacles Elimination
 */
#include <vector>
#include <queue>
#include <array>
using namespace std;
// @lc code=start
class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, int k)
    {
        queue<array<int, 3>> bfs;
        bfs.push({0, 0, k});
        grid[0][0] |= k + 1 << 1;
        int height = grid.size();
        int width = grid[0].size();
        int count = 0;
        while (!bfs.empty())
        {
            int q_len = bfs.size();
            while (q_len--)
            {
                auto row = bfs.front()[0];
                auto col = bfs.front()[1];
                auto rest_k = bfs.front()[2];
                bfs.pop();
                if (row == height - 1 && col == width - 1)
                {
                    return count;
                }
                if (rest_k + 1 < grid[row][col] >> 1)
                {
                    continue;
                }
                if (row > 0)
                {
                    if ((grid[row - 1][col] & 1) == 0 && grid[row - 1][col] >> 1 < rest_k + 1)
                    {
                        bfs.push({row - 1, col, rest_k});
                        grid[row - 1][col] = (grid[row - 1][col] & 1) + (rest_k + 1 << 1);
                    }
                    else if (rest_k > 0 && (grid[row - 1][col] >> 1) < rest_k)
                    {
                        bfs.push({row - 1, col, rest_k - 1});
                        grid[row - 1][col] = (grid[row - 1][col] & 1) + (rest_k << 1);
                    }
                }
                if (col > 0)
                {
                    if ((grid[row][col - 1] & 1) == 0 && grid[row][col - 1] >> 1 < rest_k + 1)
                    {
                        bfs.push({row, col - 1, rest_k});
                        grid[row][col - 1] = (grid[row][col - 1] & 1) + (rest_k + 1 << 1);
                    }
                    else if (rest_k > 0 && (grid[row][col - 1] >> 1) < rest_k)
                    {
                        bfs.push({row, col - 1, rest_k - 1});
                        grid[row][col - 1] = (grid[row][col - 1] & 1) + (rest_k << 1);
                    }
                }
                if (row < height - 1)
                {
                    if ((grid[row + 1][col] & 1) == 0 && grid[row + 1][col] >> 1 < rest_k + 1)
                    {
                        bfs.push({row + 1, col, rest_k});
                        grid[row + 1][col] = (grid[row + 1][col] & 1) + (rest_k + 1 << 1);
                    }
                    else if (rest_k > 0 && (grid[row + 1][col] >> 1) < rest_k)
                    {
                        bfs.push({row + 1, col, rest_k - 1});
                        grid[row + 1][col] = (grid[row + 1][col] & 1) + (rest_k << 1);
                    }
                }
                if (col < width - 1)
                {
                    if ((grid[row][col + 1] & 1) == 0 && grid[row][col + 1] >> 1 < rest_k + 1)
                    {
                        bfs.push({row, col + 1, rest_k});
                        grid[row][col + 1] = (grid[row][col + 1] & 1) + (rest_k + 1 << 1);
                    }
                    else if (rest_k > 0 && (grid[row][col + 1] >> 1) < rest_k)
                    {
                        bfs.push({row, col + 1, rest_k - 1});
                        grid[row][col + 1] = (grid[row][col + 1] & 1) + (rest_k << 1);
                    }
                }
            }
            ++count;
        }
        return -1;
    }
};
// @lc code=end