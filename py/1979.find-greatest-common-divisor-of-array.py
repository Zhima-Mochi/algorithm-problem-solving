#
# @lc app=leetcode id=1979 lang=python3
#
# [1979] Find Greatest Common Divisor of Array
#
import math
# @lc code=start


class Solution:
    def findGCD(self, nums: List[int]) -> int:
        return math.gcd(max(nums), min(nums))
# @lc code=end
