/*
 * @lc app=leetcode id=1629 lang=java
 *
 * [1629] Slowest Key
 */

// @lc code=start
class Solution {
    public char slowestKey(int[] releaseTimes, String keysPressed) {
        char candidate = keysPressed.charAt(0);
        int d = releaseTimes[0];
        int len = releaseTimes.length;
        for (int i = 1; i != len; ++i) {
            if (releaseTimes[i] - releaseTimes[i - 1] > d) {
                candidate = keysPressed.charAt(i);
                d = releaseTimes[i] - releaseTimes[i - 1];
            } else if (releaseTimes[i] - releaseTimes[i - 1] == d) {
                candidate = (char) Math.max(candidate, keysPressed.charAt(i));
            }
        }
        return candidate;
    }
}
// @lc code=end
