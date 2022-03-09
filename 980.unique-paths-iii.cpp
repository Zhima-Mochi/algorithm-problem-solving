/*
 * @lc app=leetcode id=980 lang=cpp
 *
 * [980] Unique Paths III
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    int res = 0;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int height, width;

public:
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        height = grid.size();
        width = grid[0].size();
        int start_row, start_col;
        int blank_num = 0;
        for (int i = 0; i != height; ++i)
        {
            for (int j = 0; j != width; ++j)
            {
                if (grid[i][j] == 0)
                {
                    ++blank_num;
                }
                else if (grid[i][j] == 1)
                {
                    start_row = i;
                    start_col = j;
                }
            }
        }
        dfs(grid, start_row, start_col, blank_num + 1);
        return res;
    }
    void dfs(vector<vector<int>> &grid, int row, int col, int blank_num)
    {
        if (grid[row][col] == 2)
        {
            if (blank_num == 0)
            {
                ++res;
            }
            return;
        }
        grid[row][col] = -1;
        for (auto &d : directions)
        {
            int nr = row + d[0];
            int nc = col + d[1];
            if (nr < 0 || nr >= height || nc < 0 || nc >= width || grid[nr][nc] == -1)
            {
                continue;
            }
            else
            {
                dfs(grid, nr, nc, blank_num - 1);
            }
        }
        grid[row][col] = 0;
    }
};
// @lc code=end
