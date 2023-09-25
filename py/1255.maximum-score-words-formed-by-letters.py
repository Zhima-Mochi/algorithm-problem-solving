#
# @lc app=leetcode id=1255 lang=python3
#
# [1255] Maximum Score Words Formed by Letters
#
from collections import Counter
from typing import List
# @lc code=start

# t:O(2^n) m:O(2^n)
class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        res = 0
        n = len(words)
        limit = Counter(letters)
        word_cnt = []
        for word in words:
            word_cnt.append(Counter(word))

        def getScore(counter):
            s = 0
            for alpha, num in counter.items():
                s += score[ord(alpha)-97]*num
            return s

        counter = Counter()
        @cache
        def dfs(used):
            nonlocal res, counter
            if (counter & limit) != counter:
                return
            res = max(res, getScore(counter))
            for i in range(n):
                if ((1 << i) & used) == 0:
                    used ^= (1 << i)
                    counter += word_cnt[i]
                    dfs(used)
                    used ^= (1 << i)
                    counter -= word_cnt[i]
            return

        dfs(0)
        return res

# @lc code=end
