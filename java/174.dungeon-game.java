import java.util.Arrays;

/*
 * @lc app=leetcode id=174 lang=java
 *
 * [174] Dungeon Game
 */

// @lc code=start
class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        int height = dungeon.length, width = dungeon[0].length;
        int[] dp = new int[width + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[width - 1] = 1;
        // backward induction
        for (int i = height - 1; i != -1; --i) {
            for (int j = width - 1; j != -1; --j) {
                // decide the minimum health power if knight "start at here"
                dp[j] = Math.min(dp[j], dp[j + 1]) - dungeon[i][j];
                dp[j] = Math.max(dp[j], 1);
            }
        }
        return dp[0];
    }
}
// @lc code=end
