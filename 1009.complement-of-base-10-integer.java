/*
 * @lc app=leetcode id=1009 lang=java
 *
 * [1009] Complement of Base 10 Integer
 */

// @lc code=start
class Solution {
    public int bitwiseComplement(int n) {
        int b = 1;
        while (n > b) {
            b <<= 1;
            b += 1;
        }
        return b - n;
    }
}
// @lc code=end
