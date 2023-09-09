#
# @lc app=leetcode id=2197 lang=python3
#
# [2197] Replace Non-Coprime Numbers in Array
#
from math import gcd
# @lc code=start
# t:O(nlogn) s:O(n)

class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        stk = []
        for n in nums:
            val = n
            while len(stk):
                g = gcd(stk[-1], val)
                if g == 1:
                    break
                val = val*stk.pop()//g
            stk.append(val)
        return stk
# @lc code=end
