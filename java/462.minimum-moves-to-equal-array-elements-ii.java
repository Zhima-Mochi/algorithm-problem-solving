import java.util.Arrays;

/*
 * @lc app=leetcode id=462 lang=java
 *
 * [462] Minimum Moves to Equal Array Elements II
 */

// @lc code=start
class Solution {
    public int minMoves2(int[] nums) {
        Arrays.sort(nums);
        int res = 0;
        int left = 0, right = nums.length - 1;
        while (left < right) {
            res += nums[right--] - nums[left++];
        }
        return res;
    }
}
// @lc code=end
