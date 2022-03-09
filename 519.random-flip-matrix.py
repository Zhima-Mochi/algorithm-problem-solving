#
# @lc app=leetcode id=519 lang=python3
#
# [519] Random Flip Matrix
#

# @lc code=start
import random


class Solution:
    def __init__(self, m: int, n: int):
        self.height = m
        self.width = n
        self.total = m*n
        self.seen = {}

    def flip(self) -> List[int]:
        choose = random.randint(0, self.total-1)
        self.total -= 1
        res = self.seen[choose] if choose in self.seen else choose
        self.seen[choose] = self.seen[self.total] if self.total in self.seen else self.total
        return [res//self.width, res % self.width]

    def reset(self) -> None:
        self.seen.clear()
        self.total = self.height*self.width


# Your Solution object will be instantiated and called as such:
# obj = Solution(m, n)
# param_1 = obj.flip()
# obj.reset()
# @lc code=end
