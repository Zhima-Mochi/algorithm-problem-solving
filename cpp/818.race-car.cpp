/*
 * @lc app=leetcode id=818 lang=cpp
 *
 * [818] Race Car
 */
#include <vector>
#include <climits>
using namespace std;
// @lc code=start
class Solution
{
public:
    int racecar(int target)
    {
        vector<int> dp(target + 3, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 4;

        for (int t = 3; t <= target; ++t)
        {
            int k = 32 - __builtin_clz(t);
            if (t == (1 << k) - 1)
            {
                dp[t] = k;
                continue;
            }
            for (int j = 0; j < k - 1; ++j)
            {
                dp[t] = min(dp[t], dp[t - (1 << (k - 1)) + (1 << j)] + k - 1 + j + 2);
            }
            if ((1 << k) - 1 - t < t)
            {
                dp[t] = min(dp[t], dp[(1 << k) - 1 - t] + k + 1);
            }
        }

        return dp[target];
    }
};
// @lc code=end
