/*
 * @lc app=leetcode id=959 lang=cpp
 *
 * [959] Regions Cut By Slashes
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
// t:O(N^2), s:O(N^2)
class Solution
{
    vector<string> extend_grid;
    int w;

public:
    int regionsBySlashes(vector<string> &grid)
    {
        w = grid.size();
        extend_grid = vector<string>(3 * w, string(3 * w, '0'));
        for (int i = 0; i != w; ++i)
        {
            for (int j = 0; j != w; ++j)
            {
                if (grid[i][j] == '/')
                {
                    extend_grid[3 * i][3 * j + 2] = '1';
                    extend_grid[3 * i + 1][3 * j + 1] = '1';
                    extend_grid[3 * i + 2][3 * j] = '1';
                }
                else if (grid[i][j] == '\\')
                {
                    extend_grid[3 * i][3 * j] = '1';
                    extend_grid[3 * i + 1][3 * j + 1] = '1';
                    extend_grid[3 * i + 2][3 * j + 2] = '1';
                }
            }
        }
        char color = '2';
        for (int i = 0; i != 3 * w; ++i)
        {
            for (int j = 0; j != 3 * w; ++j)
            {
                if (extend_grid[i][j] == '0')
                {
                    draw(i, j, color++);
                }
            }
        }
        return color - '2';
    }
    void draw(int i, int j, int color)
    {
        if (i < 0 || j < 0 || i >= 3 * w || j >= 3 * w)
        {
            return;
        }
        if (extend_grid[i][j] != '0')
        {
            return;
        }
        extend_grid[i][j] = color;
        draw(i - 1, j, color);
        draw(i + 1, j, color);
        draw(i, j - 1, color);
        draw(i, j + 1, color);
    }
};
// @lc code=end
