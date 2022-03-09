/*
 * @lc app=leetcode id=647 lang=java
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
    int width;
    int res = 0;

    public int countSubstrings(String s) {
        width = s.length();
        for (int i = 0; i < width; ++i) {
            helpler(s, i, i);
            helpler(s, i, i + 1);
        }
        return res;
    }

    void helpler(String s, int left, int right) {
        while (left >= 0 && right < width) {
            if (s.charAt(left--) == s.charAt(right++)) {
                ++res;
            } else {
                break;
            }
        }
    }
}
// @lc code=end
