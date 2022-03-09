#
# @lc app=leetcode id=1081 lang=python3
#
# [1081] Smallest Subsequence of Distinct Characters
#

# @lc code=start
# t:O(N), s:O(1)
class Solution:
    def smallestSubsequence(self, s: str) -> str:
        last_seen = [-1]*26
        seen = [False]*26
        for idx, val in enumerate(s):
            last_seen[ord(val)-ord('a')] = idx
        res = []
        for idx, val in enumerate(s):
            if not seen[ord(val)-ord('a')]:
                while len(res) and val < res[-1] and last_seen[ord(res[-1])-ord('a')] > idx:
                    seen[ord(res[-1])-ord('a')] = False
                    res.pop()
                res.append(val)
                seen[ord(val)-ord('a')] = True
        return ''.join(res)

# @lc code=end
