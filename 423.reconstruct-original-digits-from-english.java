import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode id=423 lang=java
 *
 * [423] Reconstruct Original Digits from English
 */

// @lc code=start
class Solution {
    public String originalDigits(String s) {
        int[] count = new int[10];
        int[] alpha = new int[26];
        char[] chars = s.toCharArray();
        for (var c : chars) {
            ++alpha[c - 'a'];
        }
        count[0] = alpha['z' - 'a'];
        count[2] = alpha['w' - 'a'];
        count[4] = alpha['u' - 'a'];
        count[6] = alpha['x' - 'a'];
        count[8] = alpha['g' - 'a'];
        count[1] = alpha['o' - 'a'];
        count[3] = alpha['h' - 'a'];
        count[7] = alpha['s' - 'a'];
        count[5] = alpha['v' - 'a'];
        count[9] = alpha['n' - 'a'];

        count[1] -= count[2] + count[4] + count[0];
        count[3] -= count[8];
        count[7] -= count[6];
        count[5] -= count[7];
        count[9] -= count[1] + count[7];
        count[9] /= 2;

        StringBuilder res = new StringBuilder();
        for (int i = 0; i != 10; ++i) {
            for (int j = 0; j != count[i]; ++j) {
                res.append((char) ('0' + i));
            }
        }
        return res.toString();
    }
}
// @lc code=end
