#
# @lc app=leetcode id=984 lang=python3
#
# [984] String Without AAA or BBB
#

# @lc code=start
class Solution:
    def strWithout3a3b(self, a: int, b: int) -> str:
        def f(x_t: int,  y_t: int, x: chr, y: chr):
            val1 = min(x_t-min(x_t, y_t), y_t)
            val2 = min(x_t-2*val1, y_t-val1)
            val3 = x_t-2*val1-val2
            val4 = y_t-val1-val2
            return f"{x}{x}{y}"*val1+f"{x}{y}"*val2+x*val3+y*val4
        if a >= b:
            return f(a, b, 'a', 'b')
        else:
            return f(b, a, 'b', 'a')

# @lc code=end
