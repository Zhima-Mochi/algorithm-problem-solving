#
# @lc app=leetcode id=802 lang=python3
#
# [802] Find Eventual Safe States
#

# @lc code=start
class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        width = len(graph)
        record = [0]*width  # 0 not seen, 1 pass, 2 terminal
        res = []

        def helpler(pos):
            if record[pos] != 0:
                return record[pos]
            else:
                record[pos] = 1
            for n in graph[pos]:
                if record[n] == 1:
                    return record[pos]
                elif record[n] == 0:
                    record[n] = helpler(n)
                    if record[n] == 1:
                        return record[pos]
            record[pos] = 2
            return record[pos]
        for i in range(width):
            if helpler(i) == 2:
                res.append(i)
        return res

# @lc code=end
