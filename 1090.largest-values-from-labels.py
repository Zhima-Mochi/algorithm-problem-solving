#
# @lc app=leetcode id=1090 lang=python3
#
# [1090] Largest Values From Labels
#
from collections import Counter
# @lc code=start


class Solution:
    def largestValsFromLabels(self, values: List[int], labels: List[int], numWanted: int, useLimit: int) -> int:
        decreasing_idx = list(range(len(values)))
        decreasing_idx.sort(key=lambda x: -values[x])
        used = Counter()
        res = 0
        for idx in decreasing_idx:
            if numWanted == 0:
                break
            used[labels[idx]] += 1
            if used[labels[idx]] <= useLimit:
                res += values[idx]
                numWanted -= 1
        return res
# @lc code=end
