#
# @lc app=leetcode id=2375 lang=python3
#
# [2375] Construct Smallest Number From DI String
#

# @lc code=start
# t:O(n), s:O(n)
class Solution:
    def smallestNumber(self, pattern: str) -> str:
        w = len(pattern)
        res = [str(x) for x in range(1, w+2)]
        cur = 0
        while cur != w:
            if pattern[cur] == "D":
                next_cur = cur
                while next_cur < w and pattern[next_cur] == "D":
                    next_cur += 1
                res[cur:next_cur+1] = res[cur:next_cur+1][::-1]
                cur = next_cur
            else:
                cur += 1
        return "".join(res)


# @lc code=end
