/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        int count = 1;
        int res = 1;
        int len = nums.size();
        for (int i = 1; i != len; ++i)
        {
            if (nums[i] > nums[i - 1])
            {
                ++count;
            }
            else
            {
                res = max(res, count);
                count = 1;
            }
        }
        return max(res, count);
    }
};
// @lc code=end
