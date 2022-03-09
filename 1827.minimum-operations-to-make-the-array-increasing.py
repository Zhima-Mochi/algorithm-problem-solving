#
# @lc app=leetcode id=1827 lang=python3
#
# [1827] Minimum Operations to Make the Array Increasing
#

# @lc code=start
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        res = 0
        prev = 0
        for n in nums:
            if n > prev:
                prev = n
            else:
                res += prev-n+1
                prev += 1
        return res
# @lc code=end
