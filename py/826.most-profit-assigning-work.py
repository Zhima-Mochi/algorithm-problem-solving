#
# @lc app=leetcode id=826 lang=python3
#
# [826] Most Profit Assigning Work
#

# @lc code=start
class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        tasks = list(zip(difficulty, profit))
        tasks.sort()
        res = 0
        ind = 0
        max_profit = 0
        for w in sorted(worker):
            while ind < len(tasks) and w >= tasks[ind][0]:
                max_profit = max(max_profit, tasks[ind][1])
                ind += 1
            res += max_profit
        return res
# @lc code=end
