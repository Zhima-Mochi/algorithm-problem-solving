#
# @lc app=leetcode id=983 lang=python3
#
# [983] Minimum Cost For Tickets
#

# @lc code=start
class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        durations = [1, 7, 30]
        days_set = set(days)

        @lru_cache
        def dp(i):
            if i > 365:
                return 0
            elif i in days_set:
                return min(dp(i+dur)+cost for cost, dur in zip(costs, durations))
            else:
                return dp(i+1)
        return dp(1)


# @lc code=end
