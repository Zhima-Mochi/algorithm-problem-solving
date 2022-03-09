#
# @lc app=leetcode id=1502 lang=python3
#
# [1502] Can Make Arithmetic Progression From Sequence
#

# @lc code=start
class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        max_val = min_val = arr[0]
        for n in arr:
            if n < min_val:
                min_val = n
            elif n > max_val:
                max_val = n
        width = len(arr)
        if (max_val-min_val) % (width-1):
            return False
        diff = (max_val-min_val)//(width-1)
        if diff == 0:
            return True
        for n in arr:
            if n > 1000000:
                n -= 3000000
            if (n-min_val) % diff:
                return False
            pos = (n-min_val)//diff
            if pos >= width or arr[pos] > 1000000:
                return False
            arr[pos] += 3000000
        return True


# @lc code=end
