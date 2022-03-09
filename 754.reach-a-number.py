#
# @lc app=leetcode id=754 lang=python3
#
# [754] Reach a Number
#

# @lc code=start
class Solution:
    def reachNumber(self, target: int) -> int:
        if target < 0:
            target *= -1
        step = int(pow(target*2, 0.5))-1
        lower_bound = (1+step)*step/2
        while lower_bound+step+1 <= target:
            step += 1
            lower_bound += step
        rest = -(target-lower_bound)
        while rest:
            step += 1
            rest += step
            rest %= 2
        return step
# @lc code=end
