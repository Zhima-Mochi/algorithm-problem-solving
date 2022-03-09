/*
 * @lc app=leetcode id=917 lang=java
 *
 * [917] Reverse Only Letters
 */

// @lc code=start
class Solution {
    public String reverseOnlyLetters(String s) {
        char[] s2 = new char[s.length()];
        int left = 0, right = s.length() - 1;
        while (left <= right) {
            if (!Character.isAlphabetic(s.charAt(left))) {
                s2[left] = s.charAt(left);
                ++left;
            } else if (!Character.isAlphabetic(s.charAt(right))) {
                s2[right] = s.charAt(right);
                --right;
            } else {
                s2[left] = s.charAt(right);
                s2[right] = s.charAt(left);
                ++left;
                --right;
            }
        }
        return String.valueOf(s2);
    }
}
// @lc code=end
