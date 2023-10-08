#
# @lc app=leetcode id=2193 lang=python3
#
# [2193] Minimum Number of Moves to Make Palindrome
#
from collections import *
from bisect import *
# @lc code=start

# t:O(n), s:O(n)
class Solution:
    def minMovesToMakePalindrome(self, s: str) -> int:
        n = len(s)
        res = 0
        i = 0
        j = n - 1
        arr_s=list(s)
        while i < j:
            k = j
            while i != k:
                if arr_s[i] == arr_s[k]:
                    for x in range(k, j):
                        arr_s[x],arr_s[x+1]=arr_s[x+1],arr_s[x]
                        res += 1
                    j -= 1
                    break
                k -= 1
            else:
                res += n // 2 - i
            i += 1
        return res


# @lc code=end
