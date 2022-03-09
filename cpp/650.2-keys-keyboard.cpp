/*
 * @lc app=leetcode id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minSteps(int n)
    {
        vector<int> dp(n + 1);
        dp[1] = 0;
        for (int i = 1; i != n; ++i)
        {
            for (int k = 2; k * i <= n; ++k)
            {
                dp[k * i] = dp[i] + 1 + (k - 1);
            }
        }
        return dp[n];
    }
};
// @lc code=end
