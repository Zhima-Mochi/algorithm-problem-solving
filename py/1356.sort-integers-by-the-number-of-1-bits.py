#
# @lc app=leetcode id=1356 lang=python3
#
# [1356] Sort Integers by The Number of 1 Bits
#

# @lc code=start
class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        return sorted(arr, key=lambda n: (Solution.countOneBit(n), n))

    @staticmethod
    def countOneBit(n: int) -> int:
        count = 0
        while n:
            if (n & 1):
                count+=1
            n >>= 1
        return count
# @lc code=end
