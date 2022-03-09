#
# @lc app=leetcode id=1385 lang=python3
#
# [1385] Find the Distance Value Between Two Arrays
#

# @lc code=start
from bisect import bisect_left


class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        arr2.sort()
        res = 0
        for n in arr1:
            lb_ind = bisect_left(arr2, n)
            if lb_ind == 0:
                if arr2[lb_ind]-n > d:
                    res += 1
            elif lb_ind == len(arr2):
                if n-arr2[lb_ind-1] > d:
                    res += 1
            elif arr2[lb_ind]-n > d and n-arr2[lb_ind-1] > d:
                res += 1
        return res

# @lc code=end
