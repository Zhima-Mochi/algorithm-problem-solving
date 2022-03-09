#
# @lc app=leetcode id=3 lang=python3
#
# [3] Longest Substring Without Repeating Characters
#

# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if s == "":
            return 0
        left_pt = 0
        right_pt = 0
        seen = {}
        res = 0
        for right_pt in range(len(s)):
            if s[right_pt] in seen and seen[s[right_pt]] >= left_pt:
                res = max(res, right_pt-left_pt)
                left_pt = seen[s[right_pt]]+1
                seen[s[right_pt]] = right_pt
            else:
                seen[s[right_pt]] = right_pt
        return max(res, right_pt-left_pt+1)
# @lc code=end
