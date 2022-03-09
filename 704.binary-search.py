#
# @lc app=leetcode id=704 lang=python3
#
# [704] Binary Search
#

# @lc code=start
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums)-1
        while left < right:
            mid = left+(right-left)//2
            if nums[mid] < target:
                left = mid+1
            else:
                right = mid
        return left if nums[left] == target else -1
# @lc code=end
