/*
 * @lc app=leetcode id=2679 lang=cpp
 *
 * [2679] Sum in a Matrix
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int matrixSum(vector<vector<int>> &nums)
    {
        for (auto &num : nums)
        {
            sort(num.begin(), num.end());
        }
        int h = nums.size(), w = nums[0].size();
        int res = 0;
        for (int j = 0; j != w; ++j)
        {
            int mv = 0;
            for (int i = 0; i != h; ++i)
            {
                mv = max(mv, nums[i][j]);
            }
            res += mv;
        }
        return res;
    }
};
// @lc code=end
