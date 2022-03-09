#
# @lc app=leetcode id=174 lang=python3
#
# [174] Dungeon Game
#

# @lc code=start
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        height, width = len(dungeon), len(dungeon[0])
        dp = [1 << 20]*(width+1)
        dp[width-1] = 1
        # backward induction
        for i in range(height-1, -1, -1):
            for j in range(width-1, -1, -1):
                # decide the minimum health power if knight "start at here"
                dp[j] = min(dp[j], dp[j + 1]) - dungeon[i][j]
                dp[j] = max(dp[j], 1)
        return dp[0]
# @lc code=end
