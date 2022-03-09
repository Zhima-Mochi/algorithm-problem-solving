/*
 * @lc app=leetcode id=1446 lang=java
 *
 * [1446] Consecutive Characters
 */

// @lc code=start
class Solution {
    public int maxPower(String s) {
        int res = 1;
        int cont = 1;
        for (int i = 1, width = s.length(); i != width; ++i) {
            if (s.charAt(i - 1) == s.charAt(i)) {
                ++cont;
            } else {
                res = Math.max(res, cont);
                if (width - i <= res) {
                    break;
                }
                cont = 1;
            }
        }
        return Math.max(res, cont);
    }
}
// @lc code=end
