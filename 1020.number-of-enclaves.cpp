/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(MN), s:O(MN)
class Solution
{
    int h;
    int w;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        h = grid.size();
        w = grid[0].size();
        int res = 0;
        for (int i = 0; i != h; ++i)
        {
            fill_zero(grid, i, 0);
            fill_zero(grid, i, w - 1);
        }
        for (int j = 0; j != w; ++j)
        {
            fill_zero(grid, 0, j);
            fill_zero(grid, h - 1, j);
        }
        for (int i = 0; i != h; ++i)
        {
            for (int j = 0; j != w; ++j)
            {
                if (grid[i][j])
                {
                    ++res;
                }
            }
        }
        return res;
    }
    void fill_zero(vector<vector<int>> &grid, int r, int c)
    {
        if (r < 0 || c < 0 || r >= h || c >= w || grid[r][c] == 0)
        {
            return;
        }
        grid[r][c] = 0;
        for (auto &d : directions)
        {
            int nr = r + d[0];
            int nc = c + d[1];
            fill_zero(grid, nr, nc);
        }
    }
};
// @lc code=end
