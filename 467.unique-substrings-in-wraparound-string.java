/*
 * @lc app=leetcode id=467 lang=java
 *
 * [467] Unique Substrings in Wraparound String
 */

// @lc code=start
class Solution {
    public int findSubstringInWraproundString(String p) {
        int[] accum_count = new int[26];
        int len = p.length();
        int pos = 0;
        while (pos != len) {
            int start_alpha = p.charAt(pos) - 'a';
            int count = 1;
            ++pos;
            while (pos != len
                    && (p.charAt(pos) - p.charAt(pos - 1) == 1 || p.charAt(pos) == 'a' && p.charAt(pos - 1) == 'z')) {
                ++count;
                ++pos;
            }
            for (int alpha = start_alpha, compare_count = 0; count != 0
                    && compare_count != 26; ++alpha, alpha %= 26, ++compare_count) {
                accum_count[alpha] = Math.max(accum_count[alpha], count--);
            }
        }
        int sum_val = 0;
        for (var n : accum_count) {
            sum_val += n;
        }
        return sum_val;
    }
}
// @lc code=end
