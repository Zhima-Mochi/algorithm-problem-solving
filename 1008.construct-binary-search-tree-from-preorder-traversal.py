#
# @lc app=leetcode id=1008 lang=python3
#
# [1008] Construct Binary Search Tree from Preorder Traversal
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
    def bstFromPreorder(self, preorder: List[int]) -> Optional[TreeNode]:
        root = TreeNode(preorder[0])
        cur = root
        node_stack = [root]
        for i in range(1, len(preorder)):
            cur_val = preorder[i]
            if node_stack[-1].val > cur_val:
                cur.left = TreeNode(cur_val)
                cur = cur.left
                node_stack.append(cur)
            else:
                while len(node_stack) and node_stack[-1].val < cur_val:
                    cur = node_stack[-1]
                    node_stack.pop()
                cur.right = TreeNode(cur_val)
                cur = cur.right
                node_stack.append(cur)
        return root

# @lc code=end
