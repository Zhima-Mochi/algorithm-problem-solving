#
# @lc app=leetcode id=903 lang=python3
#
# [903] Valid Permutations for DI Sequence
#

# @lc code=start
# t:O(n^3), s:O(n^2)
class Solution:
    def numPermsDISequence(self, s: str) -> int:
        MOD = 1000000007
        n = len(s)
        memo = [0]*(n+1)
        memo[0] = 1
        for i in range(1, n+1):
            next_memo = [0]*(n+1)
            if s[i-1] == 'I':
                for j in range(i+1):
                    next_memo[j] = sum(memo[k] for k in range(j))
                    next_memo[j] %= MOD
            else:
                for j in range(i):
                    next_memo[j] = sum(memo[k] for k in range(j, i))
                    next_memo[j] %= MOD
            memo = next_memo
        return sum(memo) % MOD

# @lc code=end
