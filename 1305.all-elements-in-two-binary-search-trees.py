#
# @lc app=leetcode id=1305 lang=python3
#
# [1305] All Elements in Two Binary Search Trees
#
from typing import *


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        res = []

        def dfs(node: TreeNode):
            cur = node
            st: List[TreeNode] = []
            while cur or len(st):
                if cur:
                    st.append(cur)
                    cur = cur.left
                else:
                    yield st[-1]
                    cur = st.pop().right
        g1 = dfs(root1)
        g2 = dfs(root2)
        v1 = next(g1, None)
        v2 = next(g2, None)
        while v1 or v2:
            if v1 and v2:
                if v1.val <= v2.val:
                    res.append(v1.val)
                    v1 = next(g1, None)
                else:
                    res.append(v2.val)
                    v2 = next(g2, None)
            elif v1:
                res.append(v1.val)
                v1 = next(g1, None)
            else:
                res.append(v2.val)
                v2 = next(g2, None)
        return res
# @lc code=end
