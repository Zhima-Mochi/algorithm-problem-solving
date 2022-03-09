#
# @lc app=leetcode id=1446 lang=python3
#
# [1446] Consecutive Characters
#

# @lc code=start
class Solution:
    def maxPower(self, s: str) -> int:
        res = 1
        cont = 1
        for i in range(1, len(s)):
            if s[i-1] == s[i]:
                cont += 1
            else:
                res = max(res, cont)
                if len(s) - i <= res:
                    break
                cont = 1
        return max(res, cont)
# @lc code=end
