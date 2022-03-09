#
# @lc app=leetcode id=795 lang=python3
#
# [795] Number of Subarrays with Bounded Maximum
#

# @lc code=start
class Solution:
    def numSubarrayBoundedMax(self, nums: List[int], left: int, right: int) -> int:
        count = 0
        confirmed = False
        prev_confirmed_distance = 0
        res = 0
        for n in nums:
            if n <= right:
                count += 1
                if n >= left:
                    res += count
                    confirmed = True
                    prev_confirmed_distance = 0
                elif confirmed:
                    prev_confirmed_distance += 1
                    res += count-prev_confirmed_distance
            else:
                count = 0
                confirmed = False
        return res
# @lc code=end
