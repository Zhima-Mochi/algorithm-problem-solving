/*
 * @lc app=leetcode id=1189 lang=java
 *
 * [1189] Maximum Number of Balloons
 */

// @lc code=start
class Solution {
    public int maxNumberOfBalloons(String text) {
        int[] count = new int[26];
        int len = text.length();
        for (int i = 0; i < len; ++i) {
            ++count[text.charAt(i) - 'a'];
        }
        return Math.min(count['b' - 'a'], Math.min(count['a' - 'a'],
                Math.min(count['l' - 'a'] / 2, Math.min(count['o' - 'a'] / 2, count['n' - 'a']))));
    }
}
// @lc code=end
