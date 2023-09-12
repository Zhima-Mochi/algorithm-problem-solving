#
# @lc app=leetcode id=1223 lang=python3
#
# [1223] Dice Roll Simulation
#

# @lc code=start
# t:O(n*m^2*k), s:O(m*k)
class Solution:
    def dieSimulator(self, n: int, rollMax: List[int]) -> int:
        MOD = 1000000007
        memo = [[0]*16 for _ in range(6)]
        for i in range(6):
            memo[i][0] = 1
        for i in range(n):
            next_memo = [[0]*16 for _ in range(6)]
            for o in range(6):
                for p in range(rollMax[o]+1):
                    if p != rollMax[o]:
                        next_memo[o][p+1] += memo[o][p]
                        next_memo[o][p+1] %= MOD
                    if p > 0:
                        for q in range(6):
                            if o != q:
                                next_memo[q][1] += memo[o][p]
                                next_memo[q][1] %= MOD
            memo = next_memo
        return sum((sum(x) % MOD for x in memo)) % MOD

# @lc code=end
