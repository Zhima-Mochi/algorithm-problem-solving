#
# @lc app=leetcode id=1328 lang=python3
#
# [1328] Break a Palindrome
#
from typing import *
# @lc code=start


class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        if len(palindrome) == 1:
            return ""
        for i in range(len(palindrome)//2):
            if palindrome[i] != 'a':
                return palindrome[:i]+'a'+palindrome[i+1:]
        return palindrome[:-1]+'b'

# @lc code=end
