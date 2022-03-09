#
# @lc app=leetcode id=1370 lang=python3
#
# [1370] Increasing Decreasing String
#

# @lc code=start
class Solution:
    def sortString(self, s: str) -> str:
        count = [0 for i in range(26)]
        rest = 0
        for c in s:
            count[ord(c)-ord('a')] += 1
            rest += 1
        res = []
        while rest:
            for i in range(26):
                if count[i]:
                    count[i] -= 1
                    rest -= 1
                    res.append(chr(ord('a')+i))
            for i in range(25, -1, -1):
                if count[i]:
                    count[i] -= 1
                    rest -= 1
                    res.append(chr(ord('a')+i))
        return ''.join(res)

# @lc code=end
