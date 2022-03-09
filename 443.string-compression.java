/*
 * @lc app=leetcode id=443 lang=java
 *
 * [443] String Compression
 */

// @lc code=start
class Solution {
    public int compress(char[] chars) {
        int len = chars.length;
        if (len == 1) {
            return 1;
        }
        int same_count = 1;
        int cur = 0;
        for (int i = 1; i < len + 1; ++i) {
            if (i != len && chars[i] == chars[i - 1]) {
                ++same_count;
            } else {
                chars[cur] = chars[i - 1];
                ++cur;
                if (same_count > 1) {
                    for (var c : String.valueOf(same_count).toCharArray()) {
                        chars[cur++] = c;
                    }
                }
                same_count = 1;
            }
        }
        return cur;
    }
}
// @lc code=end
