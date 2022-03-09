import java.util.Arrays;
import java.util.Comparator;

import org.graalvm.compiler.lir.alloc.lsra.Interval;

/*
 * @lc app=leetcode id=435 lang=java
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, (l, r) -> l[1] - r[1]);
        int endPt = Integer.MIN_VALUE;
        int count = 0;
        for (var v : intervals) {
            if (v[0] >= endPt) {
                ++count;
                endPt = v[1];
            }
        }
        return intervals.length - count;
    }
}
// @lc code=end
