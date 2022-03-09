#
# @lc app=leetcode id=1523 lang=python3
#
# [1523] Count Odd Numbers in an Interval Range
#

# @lc code=start
class Solution:
    def countOdds(self, low: int, high: int) -> int:
        return (high - low) // 2 + 1 if low % 2 else (high - low + 1) // 2
# @lc code=end
