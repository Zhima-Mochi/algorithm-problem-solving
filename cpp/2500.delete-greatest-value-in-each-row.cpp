/*
 * @lc app=leetcode id=2500 lang=cpp
 *
 * [2500] Delete Greatest Value in Each Row
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(mnlog(n)), s:O(log(n))
class Solution
{
public:
    int deleteGreatestValue(vector<vector<int>> &grid)
    {
        int h = grid.size();
        int w = grid[0].size();
        for (int i = 0; i != h; ++i)
        {
            sort(grid[i].begin(), grid[i].end());
        }
        int res = 0;
        for (int j = 0; j != w; ++j)
        {
            int max_val = grid[0][j];
            for (int i = 1; i != h; ++i)
            {
                max_val = max(max_val, grid[i][j]);
            }
            res += max_val;
        }
        return res;
    }
};
// @lc code=end
