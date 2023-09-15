#
# @lc app=leetcode id=1563 lang=python3
#
# [1563] Stone Game V
#

# @lc code=start
class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:
        n = len(stoneValue)
        memo = [[0]*n for _ in range(n)]
        maxLeft = [[0]*n for _ in range(n)]
        maxRight = [[0]*n for _ in range(n)]
        accum = [0]
        for v in stoneValue:
            accum.append(accum[-1]+v)

        for left in range(n-1, -1, -1):
            maxLeft[left][left] = maxRight[left][left] = stoneValue[left]
            sumVal = stoneValue[left]
            leftSumVal = 0
            mid = left-1
            for right in range(left+1, n):
                sumVal += stoneValue[right]
                while mid+1 < right and (leftSumVal+stoneValue[mid+1])*2 <= sumVal:
                    leftSumVal += stoneValue[mid+1]
                    mid += 1
                if left <= mid:
                    memo[left][right] = max(
                        memo[left][right], maxLeft[left][mid])
                if mid+1 < right:
                    memo[left][right] = max(
                        memo[left][right], maxRight[mid+2][right])
                if leftSumVal*2 == sumVal:
                    memo[left][right] = max(
                        memo[left][right], maxRight[mid+1][right])
                maxLeft[left][right] = max(
                    maxLeft[left][right-1], sumVal+memo[left][right])
                maxRight[left][right] = max(
                    maxRight[left+1][right], sumVal+memo[left][right])
        return memo[0][n-1]


# @lc code=end
