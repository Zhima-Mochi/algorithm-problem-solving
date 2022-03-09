#
# @lc app=leetcode id=96 lang=python3
#
# [96] Unique Binary Search Trees
#

# @lc code=start
class Solution:
    def numTrees(self, n: int) -> int:
        total_arr = [1, 1]
        while len(total_arr) <= n:
            new_value = 0
            width = len(total_arr)
            for i in range(1, width+1):
                new_value += total_arr[i-1]*total_arr[width-i]
            total_arr.append(new_value)
        return total_arr[n]
# @lc code=end
