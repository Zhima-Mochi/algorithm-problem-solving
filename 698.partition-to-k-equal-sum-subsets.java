import java.util.Arrays;

/*
 * @lc app=leetcode id=698 lang=java
 *
 * [698] Partition to K Equal Sum Subsets
 */

// @lc code=start
class Solution {

    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum_val = Arrays.stream(nums).sum();
        if (sum_val % k != 0) {
            return false;
        }
        int required_num = sum_val / k;
        Arrays.sort(nums);
        int[] subset = new int[k];
        return backtrack(subset, k, required_num, nums, nums.length - 1);
    }

    boolean backtrack(int[] subset, int k, int required_num, int[] nums, int pos) {
        if (pos == -1) {
            return true;
        }
        for (int i = 0; i != k; ++i) {
            boolean seen = false;
            for (int j = 0; j != i; ++j) {
                if (subset[i] == subset[j]) {
                    seen = true;
                    break;
                }
            }
            if (seen || subset[i] + nums[pos] > required_num) {
                continue;
            }
            subset[i] += nums[pos];
            if (backtrack(subset, k, required_num, nums, pos - 1)) {
                return true;
            }
            subset[i] -= nums[pos];
        }
        return false;
    }
}
// @lc code=end
