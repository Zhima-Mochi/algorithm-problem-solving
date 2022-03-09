/*
 * @lc app=leetcode id=1317 lang=java
 *
 * [1317] Convert Integer to the Sum of Two No-Zero Integers
 */

// @lc code=start
class Solution {
    public int[] getNoZeroIntegers(int n) {
        int left_num = 0;
        int num = n;
        int base_num = 1;
        while (num != 0) {
            if ((num % 10) > 1) {
                left_num += base_num;
            } else if ((num % 10) == 1) {
                if (num != 1) {
                    left_num += 2 * base_num;
                    num -= 10;
                }
            } else {
                left_num += base_num;
                num -= 10;
            }
            num /= 10;
            base_num *= 10;
        }
        return new int[] { left_num, n - left_num };
    }
}
// @lc code=end
