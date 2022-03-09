#
# @lc app=leetcode id=670 lang=python3
#
# [670] Maximum Swap
#

# @lc code=start
class Solution:
    def maximumSwap(self, num: int) -> int:
        num_str = list(str(num))
        left = -1
        right = -1
        for i in range(1, len(num_str)):
            if left == -1:
                right = i-1
            if num_str[i] > num_str[right]:
                right = i
                if left == -1:
                    left = right
                while left > 0 and num_str[right] > num_str[left-1]:
                    left -= 1
            elif num_str[i] == num_str[right]:
                right = i
        if left != -1:
            num_str[left], num_str[right] = num_str[right], num_str[left]
        return int(''.join(num_str))
# @lc code=end
