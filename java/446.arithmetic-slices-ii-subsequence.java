import java.awt.List;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode id=446 lang=java
 *
 * [446] Arithmetic Slices II - Subsequence
 */

// @lc code=start
class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int res = 0;
        int len = nums.length;
        if (len < 3) {
            return res;
        }
        Map<Integer, Integer>[] dp = new Map[len];
        for (int i = 0; i != len; ++i) {
            dp[i] = new HashMap<>();
            for (int j = 0; j != i; ++j) {
                var diff = (long) (nums[i]) - nums[j];
                if (diff <= Integer.MIN_VALUE || -diff <= Integer.MIN_VALUE) {
                    continue;
                }
                var intDiff = (int) diff;
                if (dp[j].containsKey(intDiff)) {
                    dp[i].put(intDiff, dp[i].getOrDefault(intDiff, 0) + dp[j].get(intDiff));
                    res += dp[j].get(intDiff);
                }
                dp[i].put(intDiff, dp[i].getOrDefault(intDiff, 0) + 1);
            }
        }
        return res;
    }
}
// @lc code=end
