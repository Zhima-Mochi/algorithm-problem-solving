/*
 * @lc app=leetcode id=1089 lang=java
 *
 * [1089] Duplicate Zeros
 */

// @lc code=start
class Solution {
    public void duplicateZeros(int[] arr) {
        int len = arr.length;
        int left = len - 1, right = left;
        for (var n : arr) {
            if (n == 0) {
                ++right;
            }
        }
        while (left != right) {
            if (arr[left] != 0) {
                if (right < len) {
                    arr[right] = arr[left];
                }
            } else {
                if (right < len) {
                    arr[right] = 0;
                }
                --right;
                if (right < len) {
                    arr[right] = 0;
                }
            }
            --left;
            --right;
        }
    }
}
// @lc code=end
