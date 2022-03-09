#
# @lc app=leetcode id=1422 lang=python3
#
# [1422] Maximum Score After Splitting a String
#

# @lc code=start
class Solution:
    def maxScore(self, s: str) -> int:
        one_count = s.count('1', 1)
        score = (1 if s[0] == '0' else 0) + one_count
        res = score
        for i in range(1, len(s)-1):
            if s[i] == '1':
                score -= 1
            else:
                score += 1
                res = max(res, score)
        return res
# @lc code=end
