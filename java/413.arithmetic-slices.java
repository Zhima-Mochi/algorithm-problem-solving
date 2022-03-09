/*
 * @lc app=leetcode id=413 lang=java
 *
 * [413] Arithmetic Slices
 */

// @lc code=start
class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int width = nums.length;
        if (width < 3) {
            return 0;
        }
        int res = 0;
        int count = 0;
        int step = nums[1] - nums[0];
        for (var i = 2; i != width; ++i) {
            if (nums[i] - nums[i - 1] == step) {
                ++count;
            } else {
                res += (count + 1) * count / 2;
                count = 0;
                step = nums[i] - nums[i - 1];
            }
        }
        res += (count + 1) * count / 2;
        return res;
    }
}
// @lc code=end
