import java.util.Arrays;
import java.util.stream.IntStream;

/*
 * @lc app=leetcode id=516 lang=java
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
class Solution {
    public int longestPalindromeSubseq(String s) {
        int width = s.length();
        int[] dp = new int[width + 1];
        int max_val = 0;
        for (int i = 0; i != width; ++i) {
            int prev_val = 0;
            for (int j = 0; i + 1 + j + 1 < width + 1; ++j) {
                int add_val = i + 1 + j + 1 == width + 1 ? 1 : 2;
                int next_prev_val = dp[j + 1];
                if (s.charAt(i) == s.charAt(width - 1 - j)) {
                    dp[j + 1] = prev_val + add_val;
                } else {
                    dp[j + 1] = Math.max(dp[j], dp[j + 1]);
                }
                prev_val = next_prev_val;
                max_val = Math.max(max_val, dp[j + 1]);
            }
            max_val = Math.max(max_val, prev_val + 1);
        }
        return max_val;
    }
}
// @lc code=end
