#
# @lc app=leetcode id=1576 lang=python3
#
# [1576] Replace All ?'s to Avoid Consecutive Repeating Characters
#

# @lc code=start
class Solution:
    def modifyString(self, s: str) -> str:
        width = len(s)
        if width == 1:
            return "a" if s == "?" else s
        s_arr = list(s)
        if s_arr[0] == '?':
            s_arr[0] = 'a' if s_arr[1] == '?' else chr((
                ord(s_arr[1]) + 1 - ord('a')) % 26 + ord('a'))
        for i in range(1, width-1):
            if s_arr[i] == '?':
                s_arr[i] = chr((ord(s_arr[i - 1]) + 1 - ord('a')) %
                               26 + ord('a'))
            if s_arr[i] == s_arr[i + 1]:
                s_arr[i] = chr((ord(s_arr[i + 1]) + 1 - ord('a')) %
                               26 + ord('a'))
        if s_arr[width - 1] == '?':
            s_arr[width - 1] = chr((ord(s_arr[width - 2]) +
                                   1 - ord('a')) % 26 + ord('a'))
        return ''.join(s_arr)
# @lc code=end
