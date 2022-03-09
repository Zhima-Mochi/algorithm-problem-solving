#
# @lc app=leetcode id=1054 lang=python3
#
# [1054] Distant Barcodes
#
import collections
# @lc code=start


class Solution:
    def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
        cnt = collections.Counter(barcodes)
        v = sorted(cnt, key=lambda k: -cnt[k])
        res = [None]*len(barcodes)
        w = len(barcodes)
        idx = 0
        for n in v:
            while cnt[n]:
                res[idx] = n
                idx += 2
                cnt[n] -= 1
                if idx >= w:
                    idx = 1
        return res
# @lc code=end
