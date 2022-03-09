#
# @lc app=leetcode id=528 lang=python3
#
# [528] Random Pick with Weight
#
import itertools
import random
import bisect
# @lc code=start


class Solution:

    def __init__(self, w: List[int]):
        self.accum = [x for x in itertools.accumulate(w)]
        self.sum_val = self.accum[-1]

    def pickIndex(self) -> int:
        return bisect.bisect_left(self.accum, random.randint(1, self.sum_val))


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()
# @lc code=end
