#
# @lc app=leetcode id=560 lang=python3
#
# [560] Subarray Sum Equals K
#
from collections import Counter
# @lc code=start


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        seen = Counter()
        sum_val = 0
        seen[0] = 1
        res = 0
        for n in nums:
            sum_val += n
            if sum_val-k in seen:
                res += seen[sum_val-k]
            seen[sum_val] += 1
        return res

# @lc code=end
