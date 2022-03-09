import java.util.Arrays;
import java.util.Comparator;

/*
 * @lc app=leetcode id=452 lang=java
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, new Comparator<int[]>() {
            @Override
            public int compare(int[] l, int[] r) {
                return l[1] < r[1] ? -1 : 1;
            }
        });
        int res = 1;
        var min_right_side = points[0][1];
        var len = points.length;
        for (int i = 1; i < len; ++i) {
            if (points[i][0] > min_right_side) {
                ++res;
                min_right_side = points[i][1];
            }
        }
        return res;
    }
}
// @lc code=end
