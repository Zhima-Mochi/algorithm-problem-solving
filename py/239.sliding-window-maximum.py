#
# @lc app=leetcode id=239 lang=python3
#
# [239] Sliding Window Maximum
#

# @lc code=start
# t:O(n), s:O(k)
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        cand = []
        for i in range(k):
            while len(cand) and nums[cand[-1]] <= nums[i]:
                cand.pop()
            cand.append(i)
        res = []
        res.append(nums[cand[0]])
        for i in range(k, len(nums)):
            while len(cand) and cand[0] <= i-k:
                cand.pop(0)
            while len(cand) and nums[cand[-1]] <= nums[i]:
                cand.pop()
            cand.append(i)
            res.append(nums[cand[0]])
        return res
# @lc code=end
