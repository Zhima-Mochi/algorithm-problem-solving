/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int dp[amount + 1];
        dp[0] = 1;
        for (int i = 1; i != amount + 1; ++i)
        {
            dp[i] = 0;
        }
        for (auto coin : coins)
        {
            for (int i = 0; i + coin <= amount; ++i)
            {
                if (dp[i])
                {
                    dp[i + coin] += dp[i];
                }
            }
        }
        return dp[amount];
    }
};
// @lc code=end
