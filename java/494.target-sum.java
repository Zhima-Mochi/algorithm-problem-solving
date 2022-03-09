import java.util.Arrays;
import java.util.Collection;

/*
 * @lc app=leetcode id=494 lang=java
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int len = nums.length;
        int sum_val = Arrays.stream(nums).sum();
        if (sum_val < target || (sum_val - target) % 2 == 1) {
            return 0;
        }
        int diff = (sum_val - target) / 2;
        int[][] dp = new int[len + 1][diff + 1];
        dp[0][0] = 1;
        for (int i = 1; i < len + 1; ++i) {
            for (int j = 0; j < diff + 1; ++j) {
                if (j + nums[i - 1] <= diff) {
                    dp[i][j + nums[i - 1]] += dp[i - 1][j];
                }
                dp[i][j] += dp[i - 1][j];
            }
        }
        return dp[len][diff];
    }
}
// @lc code=end
