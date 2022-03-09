/*
 * @lc app=leetcode id=565 lang=java
 *
 * [565] Array Nesting
 */

// @lc code=start
class Solution {
    public int arrayNesting(int[] nums) {
        int len = nums.length;
        int res = 0;
        for (int i = 0; i < len; ++i) {
            if (nums[i] >= 0) {
                nums[i] *= -1;
                nums[i] -= 1;
                int pos = -nums[i] - 1;
                int count = 1;
                while (nums[pos] >= 0) {
                    ++count;
                    nums[pos] *= -1;
                    nums[pos] -= 1;
                    pos = -nums[pos] - 1;
                }
                res = Math.max(res, count);
            }
        }
        return res;
    }
}
// @lc code=end
