#
# @lc app=leetcode id=1611 lang=python3
#
# [1611] Minimum One Bit Operations to Make Integers Zero
#
from typing import *

# @lc code=start


class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        memo = [0]*32
        memo[0] = 0
        memo[1] = 2
        for i in range(2, 32):
            memo[i] = sum(memo[:i])+2*i

        def shiftIthBit0th(i: int) -> int:
            if i < 0:
                return -1
            return memo[i]

        if n == 0:
            return 0
        elif n == 1:
            return 1
        nStr = list(reversed(bin(n)[2:]))
        l = len(nStr)

        @cache
        def dfs(idx, val) -> int:
            if idx == l-1:
                if val == '1':
                    return shiftIthBit0th(idx)+1
                else:
                    return 0
            nextVal = nStr[idx+1]
            if val == '0':
                return dfs(idx+1, nextVal)
            else:
                a = dfs(idx+1, nextVal)+shiftIthBit0th(idx)+1
                nextVal = '1' if nextVal == '0' else '0'
                b = 1+dfs(idx+1, nextVal)+shiftIthBit0th(idx)+1
                return min(a, b)
        a = dfs(0, nStr[0])
        b = 1+dfs(0, 1)
        return min(a, b)


# @lc code=end
