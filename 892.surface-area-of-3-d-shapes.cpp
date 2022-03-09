/*
 * @lc app=leetcode id=892 lang=cpp
 *
 * [892] Surface Area of 3D Shapes
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int surfaceArea(vector<vector<int>> &grid)
    {
        int height = grid.size(), width = grid[0].size();
        int res = helpler(grid[0][0], 0, 0);
        for (auto j = 1; j != width; ++j)
        {
            res += helpler(grid[0][j], grid[0][j - 1], 0);
        }
        for (auto i = 1; i != height; ++i)
        {
            res += helpler(grid[i][0], 0, grid[i - 1][0]);
        }
        for (auto i = 1; i != height; ++i)
        {
            for (auto j = 1; j != width; ++j)
            {
                res += helpler(grid[i][j], grid[i][j - 1], grid[i - 1][j]);
            }
        }
        return res;
    }
    int helpler(const int &h, const int &left_h, const int &up_h)
    {
        if (h == 0)
        {
            return 0;
        }
        else
        {

            return 2 + (h <= left_h ? 0 : 2 * (h - left_h)) + (h <= up_h ? 0 : 2 * (h - up_h));
        }
    }
};
// @lc code=end
