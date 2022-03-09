#
# @lc app=leetcode id=1822 lang=python3
#
# [1822] Sign of the Product of an Array
#

# @lc code=start
class Solution:
    def arraySign(self, nums: List[int]) -> int:
        res = 1
        for n in nums:
            if n < 0:
                res *= -1
            elif n == 0:
                return 0
        return res
# @lc code=end
