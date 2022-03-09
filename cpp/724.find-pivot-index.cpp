/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int sum = 0;
        for (auto &n : nums)
        {
            sum += n;
        }
        int len = nums.size();
        for (int i = 0; i != len; ++i)
        {
            sum -= nums[i];
            if (sum == 0)
            {
                return i;
            }
            sum -= nums[i];
        }
        return -1;
    }
};
// @lc code=end
