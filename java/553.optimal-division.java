/*
 * @lc app=leetcode id=553 lang=java
 *
 * [553] Optimal Division
 */

// @lc code=start
class Solution {
    public String optimalDivision(int[] nums) {
        StringBuilder res = new StringBuilder();
        res.append(Integer.toString(nums[0]));
        if (nums.length == 1) {
            return res.toString();
        } else if (nums.length == 2) {
            res.append('/');
            res.append(Integer.toString(nums[1]));
            return res.toString();
        } else {
            res.append("/(");
        }
        for (int i = 1; i != nums.length - 1; ++i) {
            res.append(Integer.toString(nums[i]));
            res.append('/');
        }
        res.append(Integer.toString(nums[nums.length - 1]));
        res.append(')');
        return res.toString();
    }
}
// @lc code=end
