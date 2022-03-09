import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Map;
import java.util.NavigableMap;
import java.util.TreeMap;

/*
 * @lc app=leetcode id=436 lang=java
 *
 * [436] Find Right Interval
 */

// @lc code=start
class Solution {
    public int[] findRightInterval(int[][] intervals) {
        int[] res = new int[intervals.length];
        ArrayList<Long> search_map = new ArrayList<>(intervals.length);
        for (int i = 0; i < intervals.length; ++i) {
            search_map.add((long) intervals[i][0] * intervals.length + i);
        }
        Collections.sort(search_map);
        for (int i = 0; i < intervals.length; ++i) {
            Integer ind = Collections.binarySearch(search_map, (long) intervals[i][1] * intervals.length);
            if (ind < 0) {
                ind *= -1;
                ind -= 1;
            }
            res[i] = ind != intervals.length
                    ? (int)((search_map.get(ind) % intervals.length) + intervals.length) % intervals.length
                    : -1;
        }
        return res;
    }
}
// @lc code=end
