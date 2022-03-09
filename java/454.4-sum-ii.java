import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode id=454 lang=java
 *
 * [454] 4Sum II
 */

// @lc code=start
class Solution {
    public int fourSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {
        Map<Integer, Integer> count = new HashMap<>();
        for (var n1 : nums1) {
            for (var n2 : nums2) {
                count.put(n1 + n2, count.getOrDefault(n1 + n2, 0) + 1);
            }
        }
        int result = 0;
        for (var n3 : nums3) {
            for (var n4 : nums4) {
                result += count.getOrDefault(-(n3 + n4), 0);

            }
        }
        return result;
    }
}
// @lc code=end
