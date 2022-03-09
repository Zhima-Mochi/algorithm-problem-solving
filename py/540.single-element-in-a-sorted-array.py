#
# @lc app=leetcode id=540 lang=python3
#
# [540] Single Element in a Sorted Array
#

# @lc code=start
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        left = 0
        right = len(nums)-1
        while left < right:
            mid = left + (right - left) // 2
            if (mid - left) % 2 == 1:
                if nums[mid] == nums[mid + 1]:
                    right = mid
                else:
                    left = mid + 1
            else:
                if (nums[mid] != nums[mid + 1]):
                    right = mid
                else:
                    left = mid + 2
        return nums[left]
# @lc code=end
