/*
 * @lc app=leetcode id=400 lang=java
 *
 * [400] Nth Digit
 */

// @lc code=start
class Solution {
    public int findNthDigit(int n) {
        if (n <= 9) {
            return n;
        } else {
            n -= 9;
        }
        int base = 10;
        byte len = 2;
        while (len < 9 && n > len * base * 9) {
            n -= len * base * 9;
            base *= 10;
            ++len;
        }
        base += n / len;
        n %= len;
        if (n == 0) {
            base -= 1;
        }
        return n == 0 ? String.valueOf(base).charAt(len - 1) - '0' : String.valueOf(base).charAt(n - 1) - '0';
    }
}
// @lc code=end
