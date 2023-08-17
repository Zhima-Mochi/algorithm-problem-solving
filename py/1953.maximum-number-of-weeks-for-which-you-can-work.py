#
# @lc app=leetcode id=1953 lang=python3
#
# [1953] Maximum Number of Weeks for Which You Can Work
#

# @lc code=start
# t:O(n), s:O(1)
class Solution:
    def numberOfWeeks(self, milestones: List[int]) -> int:
        mv = max(milestones)
        sv = sum(milestones)
        if sv-mv < mv:
            return 2*(sv-mv)+1
        else:
            return sv

# @lc code=end
