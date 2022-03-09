import java.util.Arrays;

/*
 * @lc app=leetcode id=473 lang=java
 *
 * [473] Matchsticks to Square
 */

// @lc code=start
class Solution {
    public boolean makesquare(int[] matchsticks) {
        int total_length = Arrays.stream(matchsticks).sum();
        if (total_length % 4 != 0) {
            return false;
        }
        int side_length = total_length / 4;
        Arrays.sort(matchsticks);
        int[] side_accum = new int[4];
        if (matchsticks[matchsticks.length - 1] > side_length) {
            return false;
        }
        return dfs(matchsticks, side_length, side_accum, matchsticks.length - 1);
    }

    boolean dfs(int[] matchsticks, int side_length, int[] side_accum, int index) {
        if (index == -1) {
            return true;
        }
        for (int i = 0; i != 4; ++i) {
            if (side_accum[i] + matchsticks[index] <= side_length) {
                boolean seen = false;
                for (int j = 0; j != i; ++j) {
                    if (side_accum[i] == side_accum[j]) {
                        seen = true;
                        break;
                    }
                }
                if (seen) {
                    continue;
                }
                side_accum[i] += matchsticks[index];
                if (dfs(matchsticks, side_length, side_accum, index - 1)) {
                    return true;
                }
                side_accum[i] -= matchsticks[index];
            }
        }
        return false;
    }
}
// @lc code=end
