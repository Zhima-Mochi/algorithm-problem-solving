/*
 * @lc app=leetcode id=498 lang=java
 *
 * [498] Diagonal Traverse
 */

// @lc code=start
class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        int height = mat.length;
        int width = mat[0].length;
        int[] res = new int[height * width];
        int row = 0, col = 0;
        int pos = 0;
        boolean upperwrad = true;
        while (row < height && col < width) {
            res[pos++] = mat[row][col];
            if (upperwrad) {
                if (row > 0 && col < width - 1) {
                    --row;
                    ++col;
                } else if (col == width - 1) {
                    upperwrad = false;
                    ++row;
                } else if (row == 0) {
                    upperwrad = false;
                    ++col;
                }
            } else {
                if (row < height - 1 && col > 0) {
                    ++row;
                    --col;
                } else if (row == height - 1) {
                    upperwrad = true;
                    ++col;
                } else if (col == 0) {
                    upperwrad = true;
                    ++row;
                }
            }
        }
        return res;
    }
}
// @lc code=end
