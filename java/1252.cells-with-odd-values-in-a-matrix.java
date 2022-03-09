/*
 * @lc app=leetcode id=1252 lang=java
 *
 * [1252] Cells with Odd Values in a Matrix
 */

// @lc code=start
class Solution {
    public int oddCells(int m, int n, int[][] indices) {
        boolean[] row_odd = new boolean[m];
        boolean[] col_odd = new boolean[n];
        for (var vec : indices) {
            row_odd[vec[0]] = !row_odd[vec[0]];
            col_odd[vec[1]] = !col_odd[vec[1]];
        }
        int row_odd_count = 0;
        int col_odd_count = 0;
        for (var b : row_odd) {
            if (b) {
                ++row_odd_count;
            }
        }
        for (var b : col_odd) {
            if (b) {
                ++col_odd_count;
            }
        }
        return row_odd_count * (n - col_odd_count) + col_odd_count * (m - row_odd_count);
    }
}
// @lc code=end
