import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
 * @lc app=leetcode id=40 lang=java
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        int width = candidates.length;
        List<Integer> pos_vec = new ArrayList<>();
        pos_vec.add(0);
        int sum = 0;
        List<List<Integer>> res = new ArrayList<>();
        while (true) {
            int last_pos = pos_vec.get(pos_vec.size() - 1);
            if (last_pos != width) {
                if (sum + candidates[last_pos] == target) {
                    List<Integer> elem = new ArrayList<>();
                    for (var pos : pos_vec) {
                        elem.add(candidates[pos]);
                    }
                    res.add(elem);
                } else if (sum + candidates[last_pos] < target) {
                    sum += candidates[last_pos];
                    pos_vec.add(last_pos + 1);
                    continue;
                }
            }

            if (last_pos == width || sum + candidates[last_pos] >= target) {
                pos_vec.remove(pos_vec.size() - 1);
                if (pos_vec.isEmpty()) {
                    break;
                }
                last_pos = pos_vec.get(pos_vec.size() - 1);
                sum -= candidates[last_pos];
                ++last_pos;
                while (last_pos != width && candidates[last_pos] == candidates[last_pos - 1]) {
                    ++last_pos;
                }
                pos_vec.set(pos_vec.size() - 1, last_pos);
            }
        }
        return res;
    }
}
// @lc code=end
