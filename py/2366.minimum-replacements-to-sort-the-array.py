#
# @lc app=leetcode id=2366 lang=python3
#
# [2366] Minimum Replacements to Sort the Array
#

# @lc code=start
# t:O(n), s:O(1)
class Solution:
    def minimumReplacement(self, nums: List[int]) -> int:
        w = len(nums)
        cur = w-2
        prev = nums[w-1]
        res = 0
        while cur > -1:
            cnt = self.divide(nums[cur], prev)
            res += cnt
            prev = nums[cur]//(cnt+1)
            cur -= 1
        return res

    def divide(self, num, goal) -> int:
        cnt = num//goal
        if num % goal:
            cnt += 1
        return cnt-1

# @lc code=end
