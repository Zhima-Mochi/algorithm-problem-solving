#
# @lc app=leetcode id=1073 lang=python3
#
# [1073] Adding Two Negabinary Numbers
#

# @lc code=start
class Solution:
    def addNegabinary(self, arr1: List[int], arr2: List[int]) -> List[int]:
        w1 = len(arr1)
        w2 = len(arr2)
        w = max(w1, w2)+3
        res = [0]*w
        for i in range(w1):
            res[i] += arr1[w1-1-i]
        for i in range(w2):
            res[i] += arr2[w2-1-i]
        for i in range(w-2):
            eliminate = min(res[i]//2, res[i+1])
            res[i] -= eliminate*2
            res[i+1] -= eliminate
            if res[i] > 1:
                res[i+1] += res[i] >> 1
                res[i+2] += res[i] >> 1
                res[i] &= 1
        while len(res) > 1 and res[-1] == 0:
            res.pop()
        res.reverse()
        return res
# @lc code=end
