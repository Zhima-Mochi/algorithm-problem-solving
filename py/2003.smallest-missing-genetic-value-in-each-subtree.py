#
# @lc app=leetcode id=2003 lang=python3
#
# [2003] Smallest Missing Genetic Value in Each Subtree
#
from collections import *
# @lc code=start

# t:O(n), s:O(n)
class Solution:
    def smallestMissingValueSubtree(self, parents: List[int], nums: List[int]) -> List[int]:
        n = len(parents)
        missing_gene = [1]*n
        node_childrens = defaultdict(list)
        for i in range(n):
            node_childrens[parents[i]].append(i)
        idx = -1
        for i in range(n):
            if nums[i] == 1:
                idx = i
                break

        is_child = set()
        cur = 1
        seen = set()

        def dfs(node, is_child):
            if node in seen:
                return
            seen.add(node)
            is_child.add(nums[node])
            for ch_node in node_childrens[node]:
                dfs(ch_node, is_child)

        while idx != -1:
            dfs(idx, is_child)
            while cur in is_child:
                cur += 1
            missing_gene[idx] = cur
            idx = parents[idx]
        return missing_gene


# @lc code=end
