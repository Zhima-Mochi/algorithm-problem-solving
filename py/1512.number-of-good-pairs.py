#
# @lc app=leetcode id=1512 lang=python3
#
# [1512] Number of Good Pairs
#

# @lc code=start
from collections import Counter


class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        seen_count = Counter()
        res = 0
        for n in nums:
            res += seen_count[n]
            seen_count[n] += 1
        return res
# @lc code=end
