#
# @lc app=leetcode id=669 lang=python3
#
# [669] Trim a Binary Search Tree
#
from typing import Optional


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
    def trimBST(self, root: Optional[TreeNode], low: int, high: int) -> Optional[TreeNode]:
        while root and (root.val > high or root.val < low):
            if root.val > high:
                root = root.left
            else:
                root = root.right

        def trimLow(node: Optional[TreeNode], low):
            if not node:
                return
            if not node.left:
                return
            elif node.left.val > low:
                trimLow(node.left, low)
            elif node.left.val == low:
                node.left.left = None
            else:
                node.left = node.left.right
                trimLow(node, low)

        def trimHigh(node: Optional[TreeNode], high):
            if not node:
                return
            if not node.right:
                return
            elif node.right.val < high:
                trimHigh(node.right, high)
            elif node.right.val == high:
                node.right.right = None
            else:
                node.right = node.right.left
                trimHigh(node, high)
        trimLow(root, low)
        trimHigh(root, high)
        return root


# @lc code=end
