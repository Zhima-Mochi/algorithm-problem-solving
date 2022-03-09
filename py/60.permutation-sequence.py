#
# @lc app=leetcode id=60 lang=python3
#
# [60] Permutation Sequence
#

# @lc code=start
# t:O(n^2), s:O(n)
class Solution:
    perm_count = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880]

    def getPermutation(self, n: int, k: int) -> str:
        used = [False]*(n+1)
        res = []
        for i in range(1, n+1):
            for num in range(1, n+1):
                if used[num]:
                    continue
                if k-self.perm_count[n-i] <= 0:
                    res.append(str(num))
                    used[num] = True
                    break
                else:
                    k -= self.perm_count[n-i]
        return ''.join(res)
# @lc code=end
