/*
 * @lc app=leetcode id=1450 lang=java
 *
 * [1450] Number of Students Doing Homework at a Given Time
 */

// @lc code=start
class Solution {
    public int busyStudent(int[] startTime, int[] endTime, int queryTime) {
        int width = startTime.length;
        int res = 0;
        for (int i = 0; i != width; ++i) {
            if (startTime[i] <= queryTime && queryTime <= endTime[i]) {
                ++res;
            }
        }
        return res;
    }
}
// @lc code=end
