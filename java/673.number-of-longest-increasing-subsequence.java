import java.util.Arrays;

/*
 * @lc app=leetcode id=673 lang=java
 *
 * [673] Number of Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
    public int findNumberOfLIS(int[] nums) {
        int len = nums.length;
        int[] dp_length = new int[len];
        Arrays.fill(dp_length, 1);
        int[] dp_count = new int[len];
        Arrays.fill(dp_count, 1);
        dp_count[len - 1] = 1;
        int max_length = 1;
        for (int i = len - 1; i != -1; --i) {
            for (int j = i + 1; j != len; ++j) {
                if (nums[j] > nums[i]) {
                    if (dp_length[j] + 1 > dp_length[i]) {
                        dp_length[i] = dp_length[j] + 1;
                        dp_count[i] = dp_count[j];
                        max_length = Math.max(max_length, dp_length[i]);
                    } else if (dp_length[j] + 1 == dp_length[i]) {
                        dp_count[i] += dp_count[j];
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i != len; ++i) {
            if (dp_length[i] == max_length) {
                res += dp_count[i];
            }
        }
        return res;
    }
}
// @lc code=end
