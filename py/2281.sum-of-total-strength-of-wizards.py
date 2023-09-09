#
# @lc app=leetcode id=2281 lang=python3
#
# [2281] Sum of Total Strength of Wizards
#
from itertools import accumulate
# @lc code=start
# t:O(n) s:O(n)
class Solution:
    def totalStrength(self, strength: List[int]) -> int:
        MOD = 1000000007
        n = len(strength)
        left, right, stk = [-1] * n, [n] * n, []
        for i, s in enumerate(strength):
            while stk and strength[stk[-1]] >= s:
                right[stk.pop()] = i
            if stk:
                left[i] = stk[-1]
            stk.append(i)

        ss = list(accumulate(accumulate(strength, initial=0), initial=0))
        res = 0
        for i, s in enumerate(strength):
            l, r = left[i] + 1, right[i] - 1
            tot = (i - l + 1) * (ss[r + 2] - ss[i + 1]
                                 ) - (r - i + 1) * (ss[i + 1] - ss[l])
            res += s * tot
            res %= MOD
        return res


# @lc code=end
