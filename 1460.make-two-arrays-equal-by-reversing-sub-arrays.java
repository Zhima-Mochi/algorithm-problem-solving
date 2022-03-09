/*
 * @lc app=leetcode id=1460 lang=java
 *
 * [1460] Make Two Arrays Equal by Reversing Sub-arrays
 */

// @lc code=start
class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
        int[] count = new int[1001];
        for (var n : target) {
            ++count[n];
        }
        for (var n : arr) {
            --count[n];
            if (count[n] == -1) {
                return false;
            }
        }
        return true;
    }
}
// @lc code=end
