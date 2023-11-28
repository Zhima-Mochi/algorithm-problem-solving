#
# @lc app=leetcode id=2147 lang=python3
#
# [2147] Number of Ways to Divide a Long Corridor
#

# @lc code=start
class Solution:
    def numberOfWays(self, corridor: str) -> int:
        MOD = 1000000007
        seat_cnt = 0
        prev_idx = -1
        prev_2_idx = -1
        ans = 1
        for i, c in enumerate(corridor):
            if c == 'S':
                seat_cnt += 1
                if seat_cnt % 2 == 0 and prev_2_idx != -1:
                    ans *= (prev_idx-prev_2_idx)
                    ans %= MOD
                prev_2_idx, prev_idx = prev_idx, i
        return ans if seat_cnt % 2 == 0 and seat_cnt else 0


# @lc code=end
