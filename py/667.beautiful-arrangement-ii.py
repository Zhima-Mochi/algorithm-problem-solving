#
# @lc app=leetcode id=667 lang=python3
#
# [667] Beautiful Arrangement II
#

# @lc code=start
class Solution:
    def constructArray(self, n: int, k: int) -> List[int]:
        if k > 1:
            res = [None]*(n+1)
            for i in range(0, min(2*k, n), 2):
                res[i] = i//2+1
                res[i+1] = k+2-res[i]
            for i in range(k+1, n):
                res[i] = i+1
            res.pop()
        else:
            res = list(range(1, n+1))
        return res


# @lc code=end
