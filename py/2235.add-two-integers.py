#
# @lc app=leetcode id=2235 lang=python3
#
# [2235] Add Two Integers
#

# @lc code=start
class Solution:
    def sum(self, num1: int, num2: int) -> int:
        if num1*num2 < 0:
            return num1+num2
        rest = num2
        res = num1
        while rest:
            next_rest = (res & rest) << 1
            res ^= rest
            rest = next_rest
        return res


# @lc code=end
