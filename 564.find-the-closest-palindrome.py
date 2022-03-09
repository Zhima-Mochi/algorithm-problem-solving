#
# @lc app=leetcode id=564 lang=python3
#
# [564] Find the Closest Palindrome
#

# @lc code=start
# t:O(log(len(n))), s:O(1)
class Solution:
    def nearestPalindromic(self, n: str) -> str:
        w = len(n)
        n_num = int(n)
        left_num = int(n[:(w+1)//2])
        res = 10**w+1
        for i in range(left_num-1, left_num+2):
            j = i if w % 2 == 0 else i//10
            while j:
                i = i*10+j % 10
                j //= 10
            if i != n_num and abs(n_num-res) > abs(n_num-i):
                res = i
        res = 10**(w-1)-1 if abs(n_num - (10**(w-1)-1)
                                 ) <= abs(n_num-res) else res
        return str(res)
# @lc code=end
