#
# @lc app=leetcode id=869 lang=python3
#
# [869] Reordered Power of 2
#

# @lc code=start
class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        n_str = str(n)
        n_str = ''.join(sorted(n_str))
        width = len(n_str)
        power2 = 1
        while len(power2_str := str(power2)) <= width:
            power2 <<= 1
            if len(power2_str) < width:
                continue
            power2_str = ''.join(sorted(power2_str))
            if power2_str == n_str:
                return True
        return False
# @lc code=end
