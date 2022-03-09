/*
 * @lc app=leetcode id=1013 lang=java
 *
 * [1013] Partition Array Into Three Parts With Equal Sum
 */

// @lc code=start
class Solution {
    public boolean canThreePartsEqualSum(int[] arr) {
        int sum_val = 0;
        for (var n : arr) {
            sum_val += n;
        }
        if (sum_val % 3 != 0) {
            return false;
        } else {
            sum_val /= 3;
        }
        int left = 1;
        int width = arr.length;
        int left_sum = arr[0];
        while (left_sum != sum_val && left != width) {
            left_sum += arr[left++];
        }
        if (left == width) {
            return false;
        }
        left_sum = arr[left++];
        while (left_sum != sum_val && left != width) {
            left_sum += arr[left++];
        }
        if (left == width) {
            return false;
        }
        return true;
    }
}
// @lc code=end
