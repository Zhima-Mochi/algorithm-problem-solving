/*
 * @lc app=leetcode id=782 lang=java
 *
 * [782] Transform to Chessboard
 */

// @lc code=start
class Solution {
    public int movesToChessboard(int[][] board) {
        int width = board[0].length;
        for (int i = 1; i != width; ++i) {
            for (int j = 1; j != width; ++j) {
                if ((board[0][0] ^ board[0][j] ^ board[i][0] ^ board[i][j]) == 1) {
                    return -1;
                }
            }
        }
        int[] row_count = new int[2];
        int[] col_count = new int[2];
        for (int i = 0; i != width; ++i) {
            if (board[0][i] == 1) {
                ++row_count[i % 2];
            }
            if (board[i][0] == 1) {
                ++col_count[i % 2];
            }
        }
        int res = 0;
        if (width % 2 == 1) {
            if (row_count[0] + row_count[1] < width / 2 || row_count[0] + row_count[1] > width / 2 + 1) {
                return -1;
            }
            if (col_count[0] + col_count[1] < width / 2 || col_count[0] + col_count[1] > width / 2 + 1) {
                return -1;
            }
            if (row_count[0] + row_count[1] == width / 2) {
                res += row_count[0];
            } else {
                res += row_count[1];
            }
            if (col_count[0] + col_count[1] == width / 2) {
                res += col_count[0];
            } else {
                res += col_count[1];
            }
        } else {
            if (row_count[0] + row_count[1] != width / 2) {
                return -1;
            }
            if (col_count[0] + col_count[1] != width / 2) {
                return -1;
            }
            res += Math.min(row_count[0], row_count[1]);
            res += Math.min(col_count[0], col_count[1]);
        }
        return res;
    }
}
// @lc code=end
