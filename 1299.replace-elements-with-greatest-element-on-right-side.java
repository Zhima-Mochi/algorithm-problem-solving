/*
 * @lc app=leetcode id=1299 lang=java
 *
 * [1299] Replace Elements with Greatest Element on Right Side
 */

// @lc code=start
class Solution {
    public int[] replaceElements(int[] arr) {
        int max_val = -1;
        for (var i = arr.length - 1; i > -1; --i) {
            int temp = arr[i];
            arr[i] = max_val;
            max_val = Math.max(max_val, temp);
        }
        return arr;
    }
}
// @lc code=end
