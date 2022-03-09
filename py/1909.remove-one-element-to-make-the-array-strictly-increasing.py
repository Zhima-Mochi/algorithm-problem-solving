#
# @lc app=leetcode id=1909 lang=python3
#
# [1909] Remove One Element to Make the Array Strictly Increasing
#

# @lc code=start
class Solution:
    def canBeIncreasing(self, nums: List[int]) -> bool:
        bound = -1
        error = 0
        for i in range(len(nums)):
            if nums[i] <= bound:
                if error == 1:
                    return False
                error = 1
                if i < 2 or nums[i-2] < nums[i]:
                    bound = nums[i]
            else:
                bound = nums[i]
        return True
# @lc code=end
