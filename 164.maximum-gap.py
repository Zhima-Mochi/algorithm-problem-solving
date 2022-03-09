#
# @lc app=leetcode id=164 lang=python3
#
# [164] Maximum Gap
#

# @lc code=start
# t:O(N), s:O(N)
class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        w = len(nums)
        if w < 2:
            return 0
        exp = 1
        max_val = max(nums)
        while max_val >= exp:
            temp = [None]*w
            cnt = [0]*10
            for n in nums:
                cnt[(n//exp) % 10] += 1
            for i in range(1, 10):
                cnt[i] += cnt[i-1]
            for i in range(w-1, -1, -1):
                digit = (nums[i]//exp) % 10
                temp[cnt[digit]-1] = nums[i]
                cnt[digit] -= 1
            nums = temp
            exp *= 10
        res = 0
        for i in range(1, w):
            res = max(res, nums[i]-nums[i-1])
        return res

# @lc code=end
