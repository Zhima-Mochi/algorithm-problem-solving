#
# @lc app=leetcode id=2195 lang=python3
#
# [2195] Append K Integers With Minimal Sum
#

# @lc code=start
# t:O(nlog(n)), s:O(log(n))
class Solution:
    def minimalKSum(self, nums: List[int], k: int) -> int:
        res = (k+1)*k//2
        nums.sort()
        prev = -1
        for n in nums:
            if n > k:
                break
            if n == prev:
                continue
            if n <= k:
                res -= n
                k += 1
                res += k
            prev = n
        return res

# @lc code=end
