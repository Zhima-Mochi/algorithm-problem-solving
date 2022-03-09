/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int len = nums.size();
        if (len < 3)
        {
            int res = nums[0];
            for (int i = 1; i != len; ++i)
            {
                res = max(res, nums[i]);
            }
            return res;
        }
        deque<int> ts = {nums[0], nums[1], nums[0] + nums[2]};
        for (int i = 3; i != len; ++i)
        {
            ts.push_back(nums[i] + max(ts[0], ts[1]));
            ts.pop_front();
        }
        return max(ts[2], ts[1]);
    }
};
// @lc code=end
