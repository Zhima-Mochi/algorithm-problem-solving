#
# @lc app=leetcode id=2824 lang=python3
#
# [2824] Count Pairs Whose Sum is Less than Target
#

# @lc code=start
class Solution:
    def countPairs(self, nums: List[int], target: int) -> int:
        nums.sort()
        n = len(nums)
        left = 0
        right = 0
        res = 0
        while right < n and left >= 0:
            if left == right:
                right += 1
            elif nums[left]+nums[right] >= target:
                left -= 1
            else:
                res += left+1
                right += 1
                left += 1
        return res
# @lc code=end
