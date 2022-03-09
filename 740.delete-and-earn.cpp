/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        int prev_del = nums[0], prev_non_del = 0;
        for (int i = 1, width = nums.size(); i != width; ++i)
        {
            if (nums[i] == nums[i - 1])
            {
                prev_del += nums[i];
            }
            else
            {
                int cur_non_del = max(prev_del, prev_non_del);
                if (nums[i] == nums[i - 1] - 1)
                {
                    prev_del = prev_non_del + nums[i];
                }
                else
                {
                    prev_del = cur_non_del + nums[i];
                }
                prev_non_del = cur_non_del;
            }
        }
        return max(prev_del, prev_non_del);
    }
};
// @lc code=end
