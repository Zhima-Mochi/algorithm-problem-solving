import java.util.Arrays;

/*
 * @lc app=leetcode id=517 lang=java
 *
 * [517] Super Washing Machines
 */

// @lc code=start
class Solution {
    public int findMinMoves(int[] machines) {
        int sum_val = Arrays.stream(machines).sum();
        int width = machines.length;
        if (sum_val % width != 0) {
            return -1;
        }
        int required_val = sum_val / width;
        int res = 0;
        int left_sum = 0;
        for (int i = 0; i != width; ++i) {
            int pressure = left_sum - i * required_val;
            left_sum += machines[i];
            if (pressure < 0) {
                // pass to left : -pressure
                // pass to right : max(machines[i] + pressure - required_val, 0)
                res = Math.max(res, -pressure + Math.max(machines[i] + pressure - required_val, 0));
            } else {
                // pass to right and receive : pressure
                res = Math.max(res, pressure);
            }
        }
        return res;
    }
}
// @lc code=end
