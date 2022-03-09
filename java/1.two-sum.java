import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode id=1 lang=java
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int len = nums.length;
        Map<Integer, Short> umap = new HashMap<>();
        for (short i = 0; i != len; ++i) {
            if (umap.containsKey(nums[i])) {

                return new int[] { umap.get(nums[i]).intValue(), i };
            } else {
                umap.put((target - nums[i]), i);
            }
        }
        return null;
    }
}
// @lc code=end
