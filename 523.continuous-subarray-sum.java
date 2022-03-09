import java.util.HashSet;
import java.util.Set;

/*
 * @lc app=leetcode id=523 lang=java
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start
class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        Set<Integer> seen = new HashSet<>();
        seen.add(nums[0] % k);
        int shift = 0;
        for (int i = 1; i != nums.length; ++i) {
            shift += nums[i];
            shift %= k;
            if (seen.contains((-shift + k) % k)) {
                return true;
            }
            seen.add((-shift + k + nums[i]) % k);
        }
        return false;
    }
}
// @lc code=end
