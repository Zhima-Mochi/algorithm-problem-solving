#
# @lc app=leetcode id=1945 lang=python3
#
# [1945] Sum of Digits of String After Convert
#

# @lc code=start
class Solution:
    def getLucky(self, s: str, k: int) -> int:
        res = 0
        for c in s:
            val = ord(c)-ord('a')+1
            res += val//10+val % 10
        k -= 1
        while k:
            next_res = 0
            while res:
                next_res += res % 10
                res //= 10
            res = next_res
            k -= 1
        return res

# @lc code=end
