#
# @lc app=leetcode id=1388 lang=python3
#
# [1388] Pizza With 3n Slices
#

# @lc code=start
# t:O(n), s:O(n)
class Solution:
    def maxSizeSlices(self, slices: List[int]) -> int:
        w = len(slices)
        turn = w//3
        prev = [[0]*(turn+1) for _ in range(2)]
        for i in range(1, w):
            for j in range(turn, 0, -1):
                prev[0][j], prev[1][j] = max(
                    prev[0][j], prev[1][j]), prev[0][j-1]+slices[i]
        res = max(prev[0][turn], prev[1][turn])
        prev = [[0]*(turn+1) for _ in range(2)]
        for i in range(0, w-1):
            for j in range(turn, 0, -1):
                prev[0][j], prev[1][j] = max(
                    prev[0][j], prev[1][j]), prev[0][j-1]+slices[i]

        res = max(res, prev[0][turn], prev[1][turn])
        return res


# @lc code=end
