/*
 * @lc app=leetcode id=1217 lang=java
 *
 * [1217] Minimum Cost to Move Chips to The Same Position
 */

// @lc code=start
class Solution {
    public int minCostToMoveChips(int[] position) {
        int odd_count = 0;
        int even_count = 0;
        for (var n : position) {
            if (n % 2 == 1) {
                ++odd_count;
            } else {
                ++even_count;
            }
        }
        return Math.min(odd_count, even_count);
    }
}
// @lc code=end
