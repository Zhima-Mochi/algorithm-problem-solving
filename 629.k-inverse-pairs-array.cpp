/*
 * @lc app=leetcode id=629 lang=cpp
 *
 * [629] K Inverse Pairs Array
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    static constexpr int mod = 1000000007;

public:
    int kInversePairs(int n, int k)
    {
        vector<vector<int>> dp(2, vector<int>(k + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            auto cur_pos = i & 1;
            auto prev_pos = 1 ^ cur_pos;
            for (int j = 0; j <= k; ++j)
            {
                dp[cur_pos][j] = (j > 0 ? dp[cur_pos][j - 1] : 0) - (j >= i ? dp[prev_pos][j - i] : 0) + dp[prev_pos][j];
                if (dp[cur_pos][j] >= mod)
                {
                    dp[cur_pos][j] -= mod;
                }
                else if (dp[cur_pos][j] < 0)
                {
                    dp[cur_pos][j] += mod;
                }
            }
        }
        return dp[n & 1][k];
    }
};
// @lc code=end
