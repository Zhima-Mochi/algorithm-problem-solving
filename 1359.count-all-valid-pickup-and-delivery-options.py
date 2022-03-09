#
# @lc app=leetcode id=1359 lang=python3
#
# [1359] Count All Valid Pickup and Delivery Options
#

# @lc code=start
class Solution:
    def countOrders(self, n: int) -> int:
        mod = 1000000007
        res = 1
        for i in range(n):
            num = (2*i+1)*(i+1)
            res *= num
            res %= mod
        return res
# @lc code=end
