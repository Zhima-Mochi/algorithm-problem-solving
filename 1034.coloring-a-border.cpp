/*
 * @lc app=leetcode id=1034 lang=cpp
 *
 * [1034] Coloring A Border
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    int new_color;
    int og_color;
    int height;
    int width;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col, int color)
    {
        new_color = color;
        og_color = grid[row][col];

        height = grid.size();
        width = grid[0].size();
        helpler(grid, row, col);
        for (int i = 0; i != height; ++i)
        {
            for (int j = 0; j != width; ++j)
            {
                if (grid[i][j] < 0)
                {
                    grid[i][j] *= -1;
                }
            }
        }
        return grid;
    }
    bool helpler(vector<vector<int>> &grid, int row, int col)
    {
        if (grid[row][col] == -new_color || grid[row][col] == -og_color)
        {
            return true;
        }
        else if (grid[row][col] != og_color)
        {
            return false;
        }
        grid[row][col] = -new_color;
        bool is_inner = true;
        for (auto &&d : directions)
        {
            if (row + d[0] >= 0 && row + d[0] < height && col + d[1] >= 0 && col + d[1] < width)
            {
                if (!helpler(grid, row + d[0], col + d[1]))
                {
                    is_inner = false;
                }
            }
            else
            {
                is_inner = false;
            }
        }
        if (is_inner)
        {
            grid[row][col] = -og_color;
        }
        return true;
    }
};
// @lc code=end
