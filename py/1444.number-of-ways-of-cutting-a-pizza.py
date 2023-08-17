#
# @lc app=leetcode id=1444 lang=python3
#
# [1444] Number of Ways of Cutting a Pizza
#

# @lc code=start
# t:O(k*m*n), s:O(k*m*n)
class Solution:

    def ways(self, pizza: List[str], k: int) -> int:
        MOD = 1000000007
        h = len(pizza)
        w = len(pizza[0])
        dp = [[[0]*(k+1) for _ in range(w)] for _ in range(h)]
        pizza_cnt = [[0 for _ in range(w)] for _ in range(h)]
        for i in range(h-1, -1, -1):
            for j in range(w-1, -1, -1):
                if pizza[i][j] == 'A':
                    pizza_cnt[i][j] = 1
        for i in range(h-1, -1, -1):
            for j in range(w-1, -1, -1):
                if j != w-1:
                    pizza_cnt[i][j] += pizza_cnt[i][j+1]
        for i in range(h-1, -1, -1):
            for j in range(w-1, -1, -1):
                if i != h-1:
                    pizza_cnt[i][j] += pizza_cnt[i+1][j]
        for i in range(h-1, -1, -1):
            for j in range(w-1, -1, -1):
                if pizza_cnt[i][j] > 0:
                    dp[i][j][1] = 1
        for m in range(2, k+1):
            for i in range(h-1, -1, -1):
                for j in range(w-1, -1, -1):
                    # row
                    for n in range(i-1, -1, -1):
                        if pizza_cnt[n][j]-pizza_cnt[i][j] > 0:
                            dp[n][j][m] += dp[i][j][m-1]
                            dp[n][j][m] %= MOD
                    # col
                    for n in range(j-1, -1, -1):
                        if pizza_cnt[i][n]-pizza_cnt[i][j] > 0:
                            dp[i][n][m] += dp[i][j][m-1]
                            dp[i][n][m] %= MOD
        return dp[0][0][k]

# @lc code=end
