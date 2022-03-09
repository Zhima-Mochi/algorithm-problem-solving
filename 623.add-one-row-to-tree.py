#
# @lc app=leetcode id=623 lang=python3
#
# [623] Add One Row to Tree
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
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        dummy = TreeNode(0, root)
        cur = dummy
        node_stack = []
        depth_stack = []
        cur_depth = 0
        while True:
            if cur and cur_depth == depth - 1:
                cur.left = TreeNode(val, cur.left, None)
                cur.right = TreeNode(val, None, cur.right)
                cur = None
            if cur:
                cur_depth += 1
                depth_stack.append(cur_depth)
                node_stack.append(cur)
                cur = cur.left
            elif len(node_stack):
                cur_depth = depth_stack[-1]
                cur = node_stack[-1].right
                node_stack.pop()
                depth_stack.pop()
            else:
                break
        return dummy.left
# @lc code=end
