/*
 * @lc app=leetcode id=665 lang=java
 *
 * [665] Non-decreasing Array
 */

// @lc code=start
class Solution {
    public boolean checkPossibility(int[] nums) {
        int error_num = 0;
        int width = nums.length;
        for (int i = 1; i != width; ++i)
        {
            if (nums[i] < nums[i - 1])
            {
                ++error_num;
                if (error_num > 1)
                {
                    return false;
                }
                if ((i < width - 1 && nums[i + 1] < nums[i - 1]) && (i != 1 && nums[i] < nums[i - 2]))
                {
                    return false;
                }
            }
        }
        return true;
    }
}
// @lc code=end

