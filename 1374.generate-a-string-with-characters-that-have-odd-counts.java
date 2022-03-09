/*
 * @lc app=leetcode id=1374 lang=java
 *
 * [1374] Generate a String With Characters That Have Odd Counts
 */

// @lc code=start
class Solution {
    public String generateTheString(int n) {
        if (n % 2 == 1) {
            return new String("a").repeat(n);
        } else {
            return new String("a").repeat(n - 1) + 'b';
        }
    }
}
// @lc code=end
