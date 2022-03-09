#
# @lc app=leetcode id=917 lang=python3
#
# [917] Reverse Only Letters
#

# @lc code=start
class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        s2 = list(s)
        left = 0
        right = len(s)-1
        while left < right:
            if not s[left].isalpha():
                left += 1
            elif not s[right].isalpha():
                right -= 1
            else:
                s2[left], s2[right] = s2[right], s2[left]
                left += 1
                right -= 1
        return "".join(s2)

# @lc code=end
