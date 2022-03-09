#
# @lc app=leetcode id=617 lang=python3
#
# [617] Merge Two Binary Trees
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
    def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
        return self.preorder(root1, root2)

    def preorder(self, node1, node2):
        if not node1 and not node2:
            return None
        if not node1:
            return node2
        if not node2:
            return node1
        new_node = TreeNode()
        new_node.val = node1.val + node2.val
        new_node.left = self.preorder(
            node1.left, node2.left)
        new_node.right = self.preorder(
            node1.right, node2.right)
        return new_node

# @lc code=end~
