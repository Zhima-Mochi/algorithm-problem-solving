#
# @lc app=leetcode id=974 lang=python3
#
# [974] Subarray Sums Divisible by K
#
from collections import Counter
# @lc code=start


class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        res = 0
        dp = Counter()
        start = 0
        for n in nums:
            dp[start] += 1
            start -= n % k
            if start < 0:
                start += k
            else:
                start %= k
            res += dp[start]
        return res

# @lc code=end
