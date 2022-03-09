/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
// t:O(N*N), s:O(N*N)
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
        {
            return -1;
        }
        if (n == 1)
        {
            return 1;
        }
        queue<pair<int, int>> positions;
        positions.push({0, 0});
        grid[0][0] = 1;
        int res = 1;
        while (!positions.empty())
        {
            ++res;
            int q_len = positions.size();
            while (q_len--)
            {
                auto position = positions.front();
                positions.pop();
                for (int i = -1; i != 2; ++i)
                {
                    for (int j = -1; j != 2; ++j)
                    {
                        int row = position.first + i;
                        int col = position.second + j;
                        if (row >= 0 && col >= 0 && row < n && col < n && grid[row][col] == 0)
                        {
                            if (row == n - 1 && col == n - 1)
                            {
                                return res;
                            }
                            grid[row][col] = 1;
                            positions.push({row, col});
                        }
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end
