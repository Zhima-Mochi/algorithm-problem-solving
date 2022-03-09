/*
 * @lc app=leetcode id=1328 lang=java
 *
 * [1328] Break a Palindrome
 */

// @lc code=start
class Solution {
    public String breakPalindrome(String palindrome) {
        int len = palindrome.length();
        if (len == 1) {
            return "";
        }
        int pos = 0;
        while (palindrome.charAt(pos) == 'a') {
            ++pos;
            if (pos >= len / 2) {
                pos = -1;
                break;
            }
        }
        if (pos == -1) {
            return palindrome.substring(0, len - 1) + 'b';
        } else {
            return palindrome.substring(0, pos) + 'a' + palindrome.substring(pos + 1);
        }
    }
}
// @lc code=end
