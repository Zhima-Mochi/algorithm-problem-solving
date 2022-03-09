/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int width = grid[0].size();
        int height = grid.size();
        int res = 4 * grid[0][0];
        for (int i = 1; i != width; ++i)
        {
            if (grid[0][i])
            {
                res += 4;
                res -= 2 * grid[0][i - 1];
            }
        }
        for (int j = 1; j != height; ++j)
        {
            if (grid[j][0])
            {
                res += 4 - 2 * grid[j - 1][0];
            }
            for (int i = 1; i != width; ++i)
            {
                if (grid[j][i])
                {
                    res += 4;
                    res -= 2 * grid[j][i - 1];
                    res -= 2 * grid[j - 1][i];
                }
            }
        }
        return res;
    }
};
// @lc code=end
