/*
 * @lc app=leetcode id=1232 lang=java
 *
 * [1232] Check If It Is a Straight Line
 */

// @lc code=start
class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        int[] prev = new int[] { coordinates[1][0] - coordinates[0][0], coordinates[1][1] - coordinates[0][1] };
        int len = coordinates.length;
        for (int i = 1; i < len; ++i) {
            int[] current_vector = new int[] { coordinates[i][0] - coordinates[i - 1][0],
                    coordinates[i][1] - coordinates[i - 1][1] };
            if (current_vector[1] * prev[0] != current_vector[0] * prev[1]) {
                return false;
            }
        }
        return true;
    }
}
// @lc code=end
