/*
 * @lc app=leetcode id=848 lang=java
 *
 * [848] Shifting Letters
 */

// @lc code=start
class Solution {
    public String shiftingLetters(String s, int[] shifts) {

        int len = s.length();
        StringBuilder s2 = new StringBuilder(len);
        s2.setLength(len);
        int shift = 0;
        for (int i = len - 1; i != -1; --i) {
            shift += shifts[i];
            shift %= 26;
            s2.setCharAt(i, (char) (((s.charAt(i) - 'a') + shift) % 26 + 'a'));
        }
        return s2.toString();
    }
}
// @lc code=end
