/*
 * @lc app=leetcode id=807 lang=cpp
 *
 * [807] Max Increase to Keep City Skyline
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        int height = grid.size();
        int width = grid[0].size();
        vector<int> row_record(height, 0);
        vector<int> col_record(width, 0);
        for (int i = 0; i != height; ++i)
        {
            for (int j = 0; j != width; ++j)
            {
                row_record[i] = max(row_record[i], grid[i][j]);
                col_record[j] = max(col_record[j], grid[i][j]);
            }
        }
        int res = 0;
        for (int i = 0; i != height; ++i)
        {
            for (int j = 0; j != width; ++j)
            {
                res += min(row_record[i], col_record[j]) - grid[i][j];
            }
        }
        return res;
    }
};
// @lc code=end
