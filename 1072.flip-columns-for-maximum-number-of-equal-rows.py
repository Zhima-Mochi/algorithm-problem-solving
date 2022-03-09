#
# @lc app=leetcode id=1072 lang=python3
#
# [1072] Flip Columns For Maximum Number of Equal Rows
#
import collections
# @lc code=start


class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        cnt = collections.Counter()
        for r in matrix:
            cnt[''.join(str(v) for v in r)] += 1
            cnt[''.join(str(v ^ 1) for v in r)] += 1
        return max(cnt.values())

# @lc code=end
