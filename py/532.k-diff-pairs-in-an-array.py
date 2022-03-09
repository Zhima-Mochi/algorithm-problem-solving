#
# @lc app=leetcode id=532 lang=python3
#
# [532] K-diff Pairs in an Array
#
from typing import List
# @lc code=start

# T:O(N log(N)), S:O(1)
class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        res = 0
        width = len(nums)
        nums.sort()
        if k > 0:
            left, right = 0, 0
            while right != width:
                if right <= width-2 and nums[right] == nums[right+1]:
                    right += 1
                elif left <= width-2 and nums[left] == nums[left+1]:
                    left += 1
                elif nums[right] - nums[left] < k:
                    right += 1
                elif nums[right] - nums[left] == k:
                    res += 1
                    left += 1
                    right += 1
                else:
                    left += 1
        else:
            pos = 1
            while pos != width:
                if nums[pos] == nums[pos - 1]:
                    res += 1
                    pos += 1
                    while pos != width and nums[pos] == nums[pos - 1]:
                        pos += 1
                else:
                    pos += 1
        return res

# @lc code=end
