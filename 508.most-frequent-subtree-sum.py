#
# @lc app=leetcode id=508 lang=python3
#
# [508] Most Frequent Subtree Sum
#
from typing import *
import collections


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

    def findFrequentTreeSum(self, root: Optional[TreeNode]) -> List[int]:
        umap = collections.Counter()
        self.postOrder(root, umap)
        max_freq = max(umap.values())
        return [v for v in umap if umap[v] == max_freq]

    def postOrder(self, root: Optional[TreeNode], umap: collections.Counter):
        if root is None:
            return
        self.postOrder(root.left, umap)
        self.postOrder(root.right, umap)
        root.val += (root.left and root.left.val or 0) + \
            (root.right and root.right.val or 0)
        umap[root.val] += 1


# @lc code=end
