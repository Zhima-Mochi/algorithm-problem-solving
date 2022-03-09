/*
 * @lc app=leetcode id=539 lang=java
 *
 * [539] Minimum Time Difference
 */

// @lc code=start
class Solution {
    public int findMinDifference(List<String> timePoints) {
        boolean[] time_seen = new boolean[60 * 24];
        for (String time : timePoints) {
            int h = Integer.parseInt(time.substring(0, 2));
            int m = Integer.parseInt(time.substring(3, 5));
            if (time_seen[60 * h + m]) {
                return 0;
            } else {
                time_seen[60 * h + m] = true;
            }
        }
        int pos_first = 0;
        while (!time_seen[pos_first]) {
            ++pos_first;
        }
        int pos_last = 60 * 24 - 1;
        while (!time_seen[pos_last]) {
            --pos_last;
        }
        int res = pos_first - pos_last + 60 * 24;
        if (res == 1) {
            return 1;
        }
        int count = 1;
        for (int i = pos_first + 1; i != pos_last + 1; ++i) {
            if (time_seen[i]) {
                res = Math.min(count, res);
                if (res == 1) {
                    return 1;
                }
                count = 1;
            } else {
                ++count;
            }
        }
        return res;
    }
}
// @lc code=end
