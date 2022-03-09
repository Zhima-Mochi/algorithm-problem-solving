#
# @lc app=leetcode id=556 lang=python3
#
# [556] Next Greater Element III
#

# @lc code=start
class Solution:
    def nextGreaterElement(self, n: int) -> int:
        n_str = list(str(n))
        width = len(n_str)
        swap_pos_left = width-2
        while swap_pos_left > -1:
            if n_str[swap_pos_left] < n_str[swap_pos_left + 1]:
                break
            swap_pos_left -= 1
        if swap_pos_left == -1:
            return -1
        else:
            swap_pos_right = width-1
            while n_str[swap_pos_right] <= n_str[swap_pos_left]:
                swap_pos_right -= 1
            n_str[swap_pos_right], n_str[swap_pos_left] = n_str[swap_pos_left], n_str[swap_pos_right]
            n_str[swap_pos_left+1:] = reversed(n_str[swap_pos_left+1:])
            res = int(''.join(n_str))
            return -1 if res > (1 << 31)-1 else res

# @lc code=end
