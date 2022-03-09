import java.util.ArrayList;
import java.util.Arrays;

/*
 * @lc app=leetcode id=1260 lang=java
 *
 * [1260] Shift 2D Grid
 */

// @lc code=start
class Solution {
    int height;
    int width;

    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        height = grid.length;
        width = grid[0].length;
        k %= height * width;
        List<List<Integer>> res = new ArrayList<>();
        if (k == 0) {
            for (var row : grid) {
                res.add(Arrays.stream(row).boxed().collect(Collectors.toList()));
            }
            return res;
        }
        reverse(grid, 0, width * height - 1);
        reverse(grid, k, width * height - 1);
        reverse(grid, 0, k - 1);
        for (var row : grid) {
            res.add(Arrays.stream(row).boxed().collect(Collectors.toList()));
        }
        return res;
    }
    void reverse(int[][] grid, int start, int end) {
        while (start < end) {
            var temp = grid[start / width][start % width];
            grid[start / width][start % width] = grid[end / width][end % width];
            grid[end / width][end % width] = temp;
            ++start;
            --end;
        }
    }
}
// @lc code=end
