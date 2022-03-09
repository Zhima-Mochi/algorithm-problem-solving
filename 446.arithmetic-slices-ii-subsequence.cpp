/*
 * @lc app=leetcode id=446 lang=cpp
 *
 * [446] Arithmetic Slices II - Subsequence
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int res = 0;
        int len = nums.size();
        if (len < 3)
        {
            return res;
        }
        vector<unordered_map<int, int>> dp(len);

        for (int i = 0; i != len; ++i)
        {
            for (int j = 0; j != i; ++j)
            {
                auto diff = static_cast<long>(nums[i]) - nums[j];
                if (diff <= INT32_MIN || -diff <= INT32_MIN)
                {
                    continue;
                }
                if (dp[j].count(diff))
                {
                    dp[i][diff] += dp[j][diff];
                    res += dp[j][diff];
                }
                dp[i][diff] += 1;
            }
        }
        return res;
    }
};
// @lc code=end
