/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(len(nums)), s:O(k)
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int res = 0;
        int w = nums.size();
        vector<int> dp(k);
        int start = 0;
        for (int i = 0; i != w; ++i)
        {
            ++dp[start];
            start -= nums[i] % k;
            if (start < 0)
            {
                start += k;
            }
            else
            {
                start %= k;
            }
            res += dp[start];
        }
        return res;
    }
};
// @lc code=end
