#
# @lc app=leetcode id=692 lang=python3
#
# [692] Top K Frequent Words
#
from collections import Counter
# @lc code=start


class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        w_count = Counter()
        for w in words:
            w_count[w] += 1

        def comp_key(x): return (-x[1], x[0])
        pq = []
        for p in w_count.items():
            pq.append(p)
            if(len(pq) == k+1):
                pq.sort(key=comp_key)
                pq.pop()
        pq.sort(key=comp_key)
        return [x[0] for x in pq]


# @lc code=end
