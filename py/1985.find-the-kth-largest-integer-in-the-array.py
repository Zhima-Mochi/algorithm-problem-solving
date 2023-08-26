#
# @lc app=leetcode id=1985 lang=python3
#
# [1985] Find the Kth Largest Integer in the Array
#
import heapq
# @lc code=start


class Wrapper:
    def __init__(self, value, comp):
        self.value = value
        self.comp = comp

    def __lt__(self, other):
        return self.comp(self.value, other.value) < 0

    def __eq__(self, other):
        return self.comp(self.value, other.value) == 0


class Solution:
    def kthLargestNumber(self, nums: List[str], k: int) -> str:
        pq = []

        def comp(x, y):
            if len(x) > len(y):
                return 1
            if len(x) < len(y):
                return -1
            w = len(x)
            for i in range(w):
                if ord(x[i]) > ord(y[i]):
                    return 1
                elif ord(x[i]) < ord(y[i]):
                    return -1
            return 0
        for n in nums:
            heapq.heappush(pq, Wrapper(n, comp))
            if len(pq) > k:
                heapq.heappop(pq)
        return heapq.heappop(pq).value

# @lc code=end
