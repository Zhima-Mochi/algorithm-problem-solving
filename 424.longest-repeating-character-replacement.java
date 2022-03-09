import java.util.ArrayList;

/*
 * @lc app=leetcode id=424 lang=java
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
class Solution {
    public int characterReplacement(String s, int k) {
        int left = 0, right = 0, len = s.length();
        int[] count = new int[26];
        int max_alpha_count = 0;
        int res = k;
        for (; right != len; ++right) {
            if (max_alpha_count < ++count[s.charAt(right) - 'A']) {
                max_alpha_count = count[s.charAt(right) - 'A'];
                res = Math.max(res, max_alpha_count + k);
            } else {
                while (right - left + 1 - max_alpha_count > k) {
                    --count[s.charAt(left++) - 'A'];
                }
            }
        }
        return res > len ? len : res;
    }
}
// @lc code=end
