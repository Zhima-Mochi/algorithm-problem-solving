#
# @lc app=leetcode id=2100 lang=python3
#
# [2100] Find Good Days to Rob the Bank
#

# @lc code=start
class Solution:
    def goodDaysToRobBank(self, security: List[int], time: int) -> List[int]:
        w = len(security)
        records = [0]*w
        count = 0
        for i in range(w-2, -1, -1):
            if security[i] <= security[i+1]:
                count += 1
            else:
                count = 0
            records[i] = count
        count = 0
        res = []
        if count >= time:
            res.append(0)
        for i in range(1, w):
            if security[i] <= security[i-1]:
                count += 1
            else:
                count = 0
            if records[i] >= time and count >= time:
                res.append(i)
        return res

# @lc code=end
