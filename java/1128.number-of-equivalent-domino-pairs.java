import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode id=1128 lang=java
 *
 * [1128] Number of Equivalent Domino Pairs
 */

// @lc code=start
class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        Map<Integer, Integer> same_count= new HashMap<>();
        int res = 0;
        for (var vec : dominoes)
        {
            Arrays.sort(vec);
            same_count.put((vec[0] << 20) + vec[1],same_count.getOrDefault((vec[0] << 20) + vec[1], 0)+1);
        }
        for (var count : same_count.values())
        {
            res += count * (count - 1) / 2;
        }
        return res;
    }
}
// @lc code=end
