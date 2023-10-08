#
# @lc app=leetcode id=1520 lang=python3
#
# [1520] Maximum Number of Non-Overlapping Substrings
#
from string import *
# @lc code=start
# t:O(n), s:O(1)

class Solution:
    def maxNumOfSubstrings(self, s: str) -> List[str]:
        seen = dict()
        n = len(s)
        for i in range(n):
            if s[i] not in seen:
                seen[s[i]] = [i, i]
            seen[s[i]][1] = i
        for char in seen:
            j = seen[char][0]
            while j <= seen[char][1]:
                if seen[char][0] <= seen[s[j]][0] and seen[char][1] >= seen[s[j]][1]:
                    pass
                else:
                    seen[char][0] = min(seen[char][0], seen[s[j]][0])
                    seen[char][1] = max(seen[char][1], seen[s[j]][1])
                j += 1
        arr = list(seen.values())
        arr.sort(key=lambda x: x[1]*(n+1)+(x[1]-x[0]))
        res = []
        tail = -1
        for d in arr:
            if tail == -1 or tail < d[0]:
                res.append(s[d[0]:d[1]+1])
                tail = d[1]
        return res


# @lc code=end
