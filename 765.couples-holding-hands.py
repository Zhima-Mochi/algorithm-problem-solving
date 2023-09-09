#
# @lc app=leetcode id=765 lang=python3
#
# [765] Couples Holding Hands
#
from collections import Counter
# @lc code=start

# t:O(nlogn) s:O(n)
class Solution:
    def minSwapsCouples(self, row: List[int]) -> int:
        w = len(row)
        group_idx = [x if x % 2 == 0 else x-1 for x in range(w)]

        def get_group(n):
            if group_idx[n] == n:
                return n
            group_idx[n] = get_group(group_idx[n])
            return group_idx[n]

        def union(a, b):
            a_g = get_group(a)
            b_g = get_group(b)
            group_idx[a_g] = group_idx[b_g]
        for i in range(0, w, 2):
            union(row[i], row[i+1])
        for i in range(w):
            get_group(i)
        cnt = Counter(group_idx)
        res = 0
        for idx in cnt:
            res += cnt[idx]//2-1
        return res

# @lc code=end
