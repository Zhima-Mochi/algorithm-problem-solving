#
# @lc app=leetcode id=1203 lang=python3
#
# [1203] Sort Items by Groups Respecting Dependencies
#
from collections import defaultdict, deque
# @lc code=start


class Solution:

    def sortItems(self, n: int, m: int, group: List[int], beforeItems: List[List[int]]) -> List[int]:
        beforeRecords = defaultdict(set)
        beforeGroupRecords = defaultdict(set)
        g = m
        for i in range(len(group)):
            if group[i] == -1:
                group[i] = g
                g += 1
        for i in range(len(beforeItems)):
            q = deque(beforeItems[i])
            beforeRecords[i].update(beforeItems[i])
            while len(q):
                elem = q.popleft()
                if elem == i:
                    return []
                if group[elem] != group[i]:
                    beforeGroupRecords[group[i]].add(group[elem])
                    beforeGroupRecords[group[i]].update(
                        beforeGroupRecords[group[elem]])
                if elem in beforeRecords:
                    beforeRecords[i].update(beforeRecords[elem])
                else:
                    for child in beforeItems[elem]:
                        if group[child] == group[i] and group[i]!=group[elem]:
                            return []
                        if child not in beforeRecords[i]:
                            q.append(child)
                            beforeRecords[i].add(child)
        group_arr = list(set(group))
        for i in range(len(group_arr)):
            for j in range(i+1, len(group_arr)):
                if group_arr[j] in beforeGroupRecords[group_arr[i]]:
                    group_arr[i], group_arr[j] = group_arr[j], group_arr[i]
        rank = dict()
        for i in range(len(group_arr)):
            rank[group_arr[i]] = i
        res = list(range(n))
        res.sort(key=lambda x: rank[group[x]])
        for i in range(n):
            for j in range(i+1, n):
                if res[j] in beforeRecords[res[i]]:
                    res[i], res[j] = res[j], res[i]
        return res


# @lc code=end
