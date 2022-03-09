#
# @lc app=leetcode id=1518 lang=python3
#
# [1518] Water Bottles
#

# @lc code=start
class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        # return numBottles + (numBottles - 1) // (numExchange - 1);
        res = numBottles
        rest_bottles = numBottles
        while rest_bottles >= numExchange:
            exchanged_bottles = rest_bottles // numExchange
            res += exchanged_bottles
            rest_bottles = rest_bottles % numExchange + exchanged_bottles
        return res
# @lc code=end
