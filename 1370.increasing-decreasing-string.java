/*
 * @lc app=leetcode id=1370 lang=java
 *
 * [1370] Increasing Decreasing String
 */

// @lc code=start
class Solution {
    public String sortString(String s) {
        int[] count = new int[26];
        int rest = 0;
        for (int i = 0; i < s.length(); ++i) {
            ++count[s.charAt(i) - 'a'];
            ++rest;
        }
        StringBuilder res = new StringBuilder();
        while (rest > 0) {
            for (int i = 0; i < 26; ++i) {
                if (count[i] > 0) {
                    --count[i];
                    --rest;
                    res.append((char) ('a' + i));
                }
            }
            for (int i = 25; i > -1; --i) {
                if (count[i] > 0) {
                    --count[i];
                    --rest;
                    res.append((char) ('a' + i));
                }
            }
        }
        return res.toString();
    }
}
// @lc code=end
