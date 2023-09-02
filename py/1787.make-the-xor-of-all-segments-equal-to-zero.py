#
# @lc app=leetcode id=1787 lang=python3
#
# [1787] Make the XOR of All Segments Equal to Zero
#
from collections import Counter
# @lc code=start


class Solution:
    def minChanges(self, nums: List[int], k: int) -> int:
        BOUND = 2**10

        w = len(nums)
        dp = [w] * BOUND
        dp[0] = 0

        for i in range(k):
            count = Counter()
            size = 0
            for j in range(i, w, k):
                count[nums[j]] += 1
                size += 1

            next_min = min(dp)

            next_dp = [next_min] * BOUND
            for mask in range(BOUND):
                for x, countx in count.items():
                    next_dp[mask] = min(next_dp[mask], dp[mask ^ x] - countx)

            dp = [val + size for val in next_dp]

        return dp[0]

# @lc code=end
