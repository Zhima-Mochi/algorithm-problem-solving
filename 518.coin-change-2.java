/*
 * @lc app=leetcode id=518 lang=java
 *
 * [518] Coin Change 2
 */

// @lc code=start
class Solution {
    public int change(int amount, int[] coins) {
        int[] dp = new int[amount + 1];
        dp[0] = 1;
        for (var coin : coins) {
            for (int i = 0; i + coin <= amount; ++i) {
                if (dp[i] > 0) {
                    dp[i + coin] += dp[i];
                }
            }
        }
        return dp[amount];
    }
}
// @lc code=end
