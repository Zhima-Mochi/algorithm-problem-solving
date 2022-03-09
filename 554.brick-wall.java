import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
 * @lc app=leetcode id=554 lang=java
 *
 * [554] Brick Wall
 */

// @lc code=start
class Solution {
    public int leastBricks(List<List<Integer>> wall) {
        Map<Integer, Integer> border_count = new HashMap<>();
        for (List<Integer> row_elem : wall) {
            int sum_val = 0;
            for (Integer elem : row_elem) {
                sum_val += elem;
                border_count.put(sum_val, border_count.getOrDefault(sum_val, 0) + 1);
            }
        }
        int height = wall.size();
        int width = wall.get(0).stream().reduce(0, Integer::sum);
        border_count.remove(width);
        int res = height;
        for (Integer val : border_count.values()) {
            res = Math.min(res, height - val);
        }
        return res;
    }
}
// @lc code=end
