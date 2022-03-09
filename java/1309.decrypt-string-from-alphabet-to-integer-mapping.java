/*
 * @lc app=leetcode id=1309 lang=java
 *
 * [1309] Decrypt String from Alphabet to Integer Mapping
 */

// @lc code=start
class Solution {
    public String freqAlphabets(String s) {
        StringBuilder res = new StringBuilder();
        int len = s.length();
        int val = 0;
        for (int i = 0; i != len; ++i) {
            if (s.charAt(i) == '#') {
                continue;
            }
            val += s.charAt(i) - '0';
            if (i + 2 < len && s.charAt(i + 2) == '#') {
                val *= 10;
            } else {
                res.append((char) ('a' + val - 1));
                val = 0;
            }
        }
        return res.toString();
    }
}
// @lc code=end
