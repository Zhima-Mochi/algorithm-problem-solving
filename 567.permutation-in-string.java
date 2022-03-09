import java.util.Arrays;

/*
 * @lc app=leetcode id=567 lang=java
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int window_len = s1.length();
        int s2_len = s2.length();
        if (window_len > s2_len) {
            return false;
        }
        int[] stat = new int[26];
        int[] all_zero = new int[26];
        // sorry to use toCharArray
        for (char c : s1.toCharArray()) {
            --stat[c - 'a'];
        }
        for (int i = 0; i != window_len; ++i) {
            ++stat[s2.charAt(i) - 'a'];
        }
        if (Arrays.equals(stat, all_zero)) {
            return true;
        }
        for (int i = window_len; i != s2_len; ++i) {
            ++stat[s2.charAt(i) - 'a'];
            --stat[s2.charAt(i - window_len) - 'a'];
            if (Arrays.equals(stat, all_zero)) {
                return true;
            }
        }
        return false;
    }
}
// @lc code=end
