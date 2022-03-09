/*
 * @lc app=leetcode id=1323 lang=java
 *
 * [1323] Maximum 69 Number
 */

// @lc code=start
class Solution {
    public int maximum69Number(int num) {
        int base = 1000;
        while (base != 0) {
            if (num > base && (num / base) % 10 == 6) {
                return num + base * 3;
            }
            base /= 10;
        }
        return num;
    }
}
// @lc code=end
