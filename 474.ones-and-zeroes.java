/*
 * @lc app=leetcode id=474 lang=java
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        int[][] dp = new int[m + 1][n + 1];
        for (var s : strs) {
            int zero_count = 0, one_count = 0;
            for (int i = 0; i < s.length(); ++i) {
                if (s.charAt(i) == '0') {
                    ++zero_count;
                }
            }
            one_count = s.length() - zero_count;
            for (int i = m - zero_count; i > -1; --i) {
                for (int j = n - one_count; j > -1; --j) {
                    if (dp[i][j] + 1 > dp[i + zero_count][j + one_count]) {
                        dp[i + zero_count][j + one_count] = dp[i][j] + 1;
                    }
                }
            }
        }
        return dp[m][n];
    }
}
// @lc code=end
