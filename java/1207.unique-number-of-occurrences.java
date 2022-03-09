/*
 * @lc app=leetcode id=1207 lang=java
 *
 * [1207] Unique Number of Occurrences
 */

// @lc code=start
class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        int[] freq = new int[2001];
        for (var n : arr) {
            ++freq[1000 + n];
        }
        boolean[] seen_freq = new boolean[1001];
        for (var n : freq) {
            if (n != 0) {
                if (seen_freq[n]) {
                    return false;
                } else {
                    seen_freq[n] = true;
                }
            }
        }
        return true;
    }
}
// @lc code=end
