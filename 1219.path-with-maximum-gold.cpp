/*
 * @lc app=leetcode id=1219 lang=cpp
 *
 * [1219] Path with Maximum Gold
 */
#include <vector>
using namespace std;
// @lc code=start

// t:O(mn*mn), s:O(mn)
class Solution
{
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int w;
    int h;
    int res = 0;

public:
    int getMaximumGold(vector<vector<int>> &grid)
    {
        h = grid.size();
        w = grid[0].size();
        for (int i = 0; i != h; ++i)
        {
            for (int j = 0; j != w; ++j)
            {
                if (grid[i][j] > 0)
                {
                    dfs(grid, i, j, 0);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>> &grid, int row, int col, int val)
    {

        val += grid[row][col];
        res = max(res, val);
        grid[row][col] *= -1;
        for (auto &d : directions)
        {
            int r = row + d[0];
            int c = col + d[1];
            if (r < 0 || c < 0 || r >= h || c >= w || grid[r][c] <= 0)
            {
            }
            else
            {
                dfs(grid, r, c, val);
            }
        }
        grid[row][col] *= -1;
    }
};
// @lc code=end
