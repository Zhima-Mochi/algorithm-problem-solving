#
# @lc app=leetcode id=970 lang=python3
#
# [970] Powerful Integers
#

# @lc code=start
class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        val = set()
        _x = 1
        for i in range(20):
            _y = 1
            for j in range(20):
                if _x+_y <= bound:
                    val.add(_x+_y)
                _y *= y
            _x *= x
        return list(val)

# @lc code=end
