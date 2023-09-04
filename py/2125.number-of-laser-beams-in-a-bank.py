#
# @lc app=leetcode id=2125 lang=python3
#
# [2125] Number of Laser Beams in a Bank
#

# @lc code=start
# t:O(m*n), s:O(1)
class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        prev = 0
        res = 0
        for r in bank:
            cur = 0
            for n in r:
                if n == "1":
                    cur += 1
            if cur > 0:
                res += prev*cur
                prev = cur
        return res

# @lc code=end
