#
# @lc app=leetcode id=517 lang=python3
#
# [517] Super Washing Machines
#

# @lc code=start
class Solution:
    def findMinMoves(self, machines: List[int]) -> int:
        sum_val = sum(machines)
        width = len(machines)
        if sum_val % width:
            return -1
        required_val = sum_val//width
        res = 0
        left_sum = 0
        for i in range(width):
            pressure = left_sum-i*required_val
            left_sum += machines[i]
            if pressure < 0:
                # pass to left : -pressure
                # pass to right : max(machines[i] + pressure - required_val, 0)
                res = max(res, -pressure +
                          max(machines[i] + pressure - required_val, 0))
            else:
                # pass to right and receive : pressure
                res = max(res, pressure)
        return res


# @lc code=end
