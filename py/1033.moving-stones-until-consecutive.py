#
# @lc app=leetcode id=1033 lang=python3
#
# [1033] Moving Stones Until Consecutive
#

# @lc code=start
# t:O(1), s:O(1)
class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        arr = [a, b, c]
        arr.sort()
        if arr[0] + 2 < arr[1] and arr[1] + 2 < arr[2]:
            return [2, arr[2] - arr[0] - 2]
        elif arr[0] + 2 == arr[1] or arr[1] + 2 == arr[2]:
            return [1, arr[2] - arr[0] - 2]
        else:
            return [1 if arr[2] - arr[0] > 2 else 0, arr[2] - arr[0] - 2]
# @lc code=end
