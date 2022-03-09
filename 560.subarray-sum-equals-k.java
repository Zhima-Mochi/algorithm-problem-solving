import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode id=560 lang=java
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> seen = new HashMap<>();
        int sum_val = 0;
        seen.put(0, 1);
        int res = 0;
        for (int n : nums) {
            sum_val += n;
            if (seen.containsKey(sum_val - k)) {
                res += seen.get(sum_val - k);
            }
            seen.put(sum_val, seen.getOrDefault(sum_val, 0) + 1);
        }
        return res;
    }
}
// @lc code=end
