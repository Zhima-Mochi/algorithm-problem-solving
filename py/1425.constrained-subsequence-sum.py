#
# @lc app=leetcode id=1425 lang=python3
#
# [1425] Constrained Subsequence Sum
#
from typing import *
from collections import *
from heapq import *
# @lc code=start

# t:O(n), s:O(n)
class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        res = max(nums)
        if res <= 0:
            return res
        cur = 1
        dq = deque([0])
        while cur < n:
            while len(dq) and dq[0]+k < cur:
                dq.popleft()
            nums[cur] = max(nums[dq[0]], 0) + nums[cur]
            res = max(res, nums[cur])
            while len(dq) and nums[dq[-1]] <= nums[cur]:
                dq.pop()
            dq.append(cur)
            cur += 1
        return res


# @lc code=end
