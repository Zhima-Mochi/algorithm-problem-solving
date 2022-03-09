import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode id=1512 lang=java
 *
 * [1512] Number of Good Pairs
 */

// @lc code=start
class Solution {
    public int numIdenticalPairs(int[] nums) {
        Map<Integer, Integer> seen_count = new HashMap<>();
        int res = 0;
        for (int n : nums) {
            res += seen_count.getOrDefault(n, 0);
            seen_count.put(n, seen_count.getOrDefault(n, 0) + 1);
        }
        return res;
    }
}
// @lc code=end
