#
# @lc app=leetcode id=1417 lang=python3
#
# [1417] Reformat The String
#

# @lc code=start
class Solution:
    def reformat(self, s: str) -> str:
        width = len(s)
        if width == 1:
            return s
        s = [c for c in s]
        num_count = 0
        for c in s:
            if c.isdigit():
                num_count += 1
        if num_count != width//2 and num_count != (width+1)/2:
            return ""
        num_first = num_count > width//2
        left = 0
        right = width-2 if width % 2 else width-1
        while left < width and right > -1:
            if num_first:
                if s[left].isdigit():
                    left += 2
                    continue
                if s[right].isalpha():
                    right -= 2
                    continue
            else:
                if not s[left].isdigit():
                    left += 2
                    continue
                if not s[right].isalpha():
                    right -= 2
                    continue
            s[left], s[right] = s[right], s[left]
            left += 2
            right -= 2
        return ''.join(s)

# @lc code=end
