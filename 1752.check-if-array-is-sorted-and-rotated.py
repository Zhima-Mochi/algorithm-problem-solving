#
# @lc app=leetcode id=1752 lang=python3
#
# [1752] Check if Array Is Sorted and Rotated
#

# @lc code=start
class Solution:
    def check(self, nums: List[int]) -> bool:
        disc_cnt = 0
        prev = 0
        for n in nums:
            if n < prev:
                disc_cnt += 1
                if disc_cnt == 2:
                    return False
            if disc_cnt == 1 and n > nums[0]:
                return False
            prev = n
        return True
# @lc code=end
