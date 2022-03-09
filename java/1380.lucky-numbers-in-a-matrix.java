import java.util.ArrayList;

/*
 * @lc app=leetcode id=1380 lang=java
 *
 * [1380] Lucky Numbers in a Matrix
 */

// @lc code=start
class Solution {
    public List<Integer> luckyNumbers(int[][] matrix) {
        int height = matrix.length;
        int width = matrix[0].length;
        int[] row = new int[height], col = new int[width];
        Arrays.fill(row, 100001);
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i != height; ++i) {
            for (int j = 0; j != width; ++j) {
                row[i] = Math.min(row[i], matrix[i][j]);
                col[j] = Math.max(col[j], matrix[i][j]);
            }
        }
        for (int i = 0; i != height; ++i) {
            for (int j = 0; j != width; ++j) {
                if (row[i] == col[j]) {
                    res.add(row[i]);
                    break;
                }
            }
        }
        return res;
    }
}
// @lc code=end
