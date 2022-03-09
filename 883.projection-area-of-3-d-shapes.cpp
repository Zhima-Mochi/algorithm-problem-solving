/*
 * @lc app=leetcode id=883 lang=cpp
 *
 * [883] Projection Area of 3D Shapes
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int projectionArea(vector<vector<int>> &grid)
    {
        int height = grid.size();
        int width = grid[0].size();
        int res = 0;
        auto row_max = grid[0];
        for (int i = 0; i != height; ++i)
        {
            int col_max = grid[i][0];

            for (int j = 0; j != width; ++j)
            {
                if (grid[i][j])
                {
                    ++res;
                    row_max[j] = max(row_max[j], grid[i][j]);
                    col_max = max(col_max, grid[i][j]);
                }
            }
            res += col_max;
        }
        for (auto &n : row_max)
        {
            res += n;
        }
        return res;
        
    }
};
// @lc code=end
