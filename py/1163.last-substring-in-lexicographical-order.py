#
# @lc app=leetcode id=1163 lang=python3
#
# [1163] Last Substring in Lexicographical Order
#

# @lc code=start

# t:O(n), s:O(1)
class Solution:
    def lastSubstring(self, s: str) -> str:
        left, right = 0, 1
        n = len(s)
        while right < n:
            step = 0
            while right+step < n and s[left+step] == s[right+step]:
                step += 1
            if right+step < n and s[left+step] < s[right+step]:
                left, right = right, max(right+1, left+step+1)
            else:
                right += step+1
        return s[left:]

# @lc code=end
