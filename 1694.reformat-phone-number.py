#
# @lc app=leetcode id=1694 lang=python3
#
# [1694] Reformat Phone Number
#

# @lc code=start
class Solution:
    def reformatNumber(self, number: str) -> str:
        res = []
        count = 0
        for c in number:
            if c.isdigit():
                if count == 3:
                    res.append('-')
                    count = 0
                count += 1
                res.append(c)
        if len(res) > 1 and count == 1:
            res[-2], res[-3] = res[-3], res[-2]
        return ''.join(res)

# @lc code=end
