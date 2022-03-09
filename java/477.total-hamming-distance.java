/*
 * @lc app=leetcode id=477 lang=java
 *
 * [477] Total Hamming Distance
 */

// @lc code=start
class Solution {
    public int totalHammingDistance(int[] nums) {
        int res = 0;
        int len = nums.length;
        for (int i = 0; i != 31; ++i) {
            int count = 0;
            for (var n : nums) {
                count += (n >> i) & 1;
            }
            res += count * (len - count);
        }
        return res;
    }
}
// @lc code=end
